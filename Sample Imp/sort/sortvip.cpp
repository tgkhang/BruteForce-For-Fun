#pragma once
#include <algorithm>
#include <concepts>
#include <functional>
#include <iterator>
#include <ranges>
#include <span>
#include <type_traits>
#include <vector>

namespace sorting {

// ---------- Concepts ----------
template <typename T>
concept Sortable = std::totally_ordered<T>;

template <typename R, typename T = std::ranges::range_value_t<R>>
concept SortableRange = std::ranges::random_access_range<R> &&
                        std::totally_ordered<T> &&
                        std::swappable<std::ranges::range_reference_t<R>>;

// ---------- Comparators ----------
template <typename T>
inline constexpr auto ascending = std::less<T>{};
template <typename T>
inline constexpr auto descending = std::greater<T>{};

// =====================================================================
//  O(n²) algorithms — educational / small-data
// =====================================================================

/// Bubble sort (stable). Early-exit for O(n) best case.
template <SortableRange R, typename Cmp = std::less<>>
void bubble_sort(R&& range, Cmp cmp = {}) {
    auto first = std::ranges::begin(range);
    auto last = std::ranges::end(range);
    const auto n = std::ranges::distance(first, last);
    if (n < 2) return;

    for (decltype(n) i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (decltype(n) j = 0; j < n - 1 - i; ++j) {
            if (cmp(*(first + j + 1), *(first + j))) {
                std::ranges::iter_swap(first + j, first + j + 1);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/// Selection sort (unstable). Minimal swaps: O(n).
template <SortableRange R, typename Cmp = std::less<>>
void selection_sort(R&& range, Cmp cmp = {}) {
    auto first = std::ranges::begin(range);
    auto last = std::ranges::end(range);
    for (auto i = first; i != last; ++i) {
        auto minIt = i;
        for (auto j = std::next(i); j != last; ++j)
            if (cmp(*j, *minIt)) minIt = j;
        if (minIt != i) std::ranges::iter_swap(i, minIt);
    }
}

/// Insertion sort (stable). Excellent for nearly-sorted data.
template <SortableRange R, typename Cmp = std::less<>>
void insertion_sort(R&& range, Cmp cmp = {}) {
    auto first = std::ranges::begin(range);
    auto last = std::ranges::end(range);
    if (first == last) return;

    for (auto i = std::next(first); i != last; ++i) {
        auto key = std::ranges::iter_move(i);
        auto j = i;
        while (j != first && cmp(key, *std::prev(j))) {
            *j = std::ranges::iter_move(std::prev(j));
            --j;
        }
        *j = std::move(key);
    }
}

// =====================================================================
//  O(n log n) algorithms
// =====================================================================

/// Merge sort (stable). O(n) auxiliary space.
template <SortableRange R, typename Cmp = std::less<>>
void merge_sort(R&& range, Cmp cmp = {}) {
    using T = std::ranges::range_value_t<R>;
    std::vector<T> buffer(std::ranges::size(range));

    auto first = std::ranges::begin(range);
    auto sortRec = [&](auto self, auto lo, auto hi) -> void {
        if (hi - lo < 2) return;
        auto mid = lo + (hi - lo) / 2;
        self(self, lo, mid);
        self(self, mid, hi);

        // merge
        auto i = lo, j = mid, k = 0;
        while (i < mid && j < hi)
            buffer[k++] = cmp(*j, *i) ? std::move(*j++) : std::move(*i++);
        while (i < mid) buffer[k++] = std::move(*i++);
        while (j < hi) buffer[k++] = std::move(*j++);
        std::move(buffer.begin(), buffer.begin() + k, lo);
    };

    sortRec(sortRec, first, std::ranges::end(range));
}

/// Quick sort (unstable, in-place). Median-of-three pivot + introspective fallback.
template <SortableRange R, typename Cmp = std::less<>>
void quick_sort(R&& range, Cmp cmp = {}) {
    auto first = std::ranges::begin(range);
    auto last = std::ranges::end(range);

    auto median3 = [&](auto a, auto b, auto c) {
        if (cmp(*b, *a)) std::swap(a, b);
        if (cmp(*c, *b)) std::swap(b, c);
        if (cmp(*b, *a)) std::swap(a, b);
        return b;
    };

    auto rec = [&](auto self, auto lo, auto hi, int depth) -> void {
        while (hi - lo > 16) {
            if (depth-- == 0) {  // introsort fallback
                std::make_heap(lo, hi, cmp);
                std::sort_heap(lo, hi, cmp);
                return;
            }
            auto pivot = median3(lo, lo + (hi - lo) / 2, hi - 1);
            auto mid = std::partition(lo, hi,
                                      [&](auto& x) { return cmp(x, *pivot); });
            // recurse on smaller side, iterate on larger (bounded stack)
            if (mid - lo < hi - mid) {
                self(self, lo, mid, depth);
                lo = mid;
            } else {
                self(self, mid, hi, depth);
                hi = mid;
            }
        }
        insertion_sort(std::span{lo, hi}, cmp);
    };

    rec(rec, first, last, 2 * std::bit_width(std::ranges::size(range)));
}

/// Heap sort (unstable, in-place, O(1) extra space).
template <SortableRange R, typename Cmp = std::less<>>
void heap_sort(R&& range, Cmp cmp = {}) {
    std::make_heap(std::ranges::begin(range), std::ranges::end(range), cmp);
    std::sort_heap(std::ranges::begin(range), std::ranges::end(range), cmp);
}

/// Shell sort (unstable, in-place). Ciura gap sequence + extension.
template <SortableRange R, typename Cmp = std::less<>>
void shell_sort(R&& range, Cmp cmp = {}) {
    static constexpr int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    auto first = std::ranges::begin(range);
    const auto n = std::ranges::distance(first, std::ranges::end(range));

    for (auto g : std::views::reverse(gaps)) {
        if (g >= n) continue;
        for (decltype(n) i = g; i < n; ++i) {
            auto key = std::ranges::iter_move(first + i);
            auto j = i;
            while (j >= g && cmp(key, *(first + j - g))) {
                *(first + j) = std::ranges::iter_move(first + j - g);
                j -= g;
            }
            *(first + j) = std::move(key);
        }
    }
}

// =====================================================================
//  Linear-time (non-comparison) — integral keys only
// =====================================================================

/// Counting sort. Requires non-negative integral keys with known max.
template <std::ranges::random_access_range R>
    requires std::integral<std::ranges::range_value_t<R>>
void counting_sort(R&& range, std::ranges::range_value_t<R> maxVal) {
    using T = std::ranges::range_value_t<R>;
    std::vector<std::size_t> count(static_cast<std::size_t>(maxVal) + 1, 0);
    for (auto& x : range) ++count[static_cast<std::size_t>(x)];

    std::size_t idx = 0;
    for (std::size_t v = 0; v < count.size(); ++v)
        while (count[v]--) range[idx++] = static_cast<T>(v);
}

/// LSD radix sort for non-negative integers. Stable per-digit counting sort.
template <std::ranges::random_access_range R>
    requires std::integral<std::ranges::range_value_t<R>>
void radix_sort(R&& range) {
    using T = std::ranges::range_value_t<R>;
    using U = std::make_unsigned_t<T>;
    if (std::ranges::empty(range)) return;

    U maxVal = 0;
    for (auto& x : range) maxVal = std::max(maxVal, static_cast<U>(x));

    std::vector<T> buffer(std::ranges::size(range));
    for (U exp = 1; maxVal / exp > 0; exp *= 10) {
        std::size_t count[10]{};
        for (auto& x : range) ++count[(static_cast<U>(x) / exp) % 10];
        for (int i = 1; i < 10; ++i) count[i] += count[i - 1];

        for (auto it = std::ranges::rbegin(range);
             it != std::ranges::rend(range); ++it) {
            auto d = (static_cast<U>(*it) / exp) % 10;
            buffer[--count[d]] = *it;
        }
        std::ranges::copy(buffer, std::ranges::begin(range));
    }
}

}  // namespace sorting