# Trie ladder

Base implementation: `Sample Imp/tree/trie/trie_tree_implementation.cpp`

Solve in order. File naming follows the rest of `Practice/` (e.g. `706d2d.cpp`, `cses1731.cpp`, `lc208.cpp`).

---

## Stage 1 — Basic string trie (insert / search / prefix)

| Done | Problem | Idea |
| --- | --- | --- |
| [x] | [LC 208 - Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/) | the template itself |
| [x] | [LC 14 - Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | is trie necessary for this problem? | 
| [x] | [LC 720 - Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/) | DFS only through end-of-word nodes |
| [x] | [LC 648 - Replace Words](https://leetcode.com/problems/replace-words/) | shortest prefix that is a word |
| [x] | [LC 677 - Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/) | store sum on each node |
| [x] | [LC 1268 - Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) | DFS lexicographic from prefix node |
| [ ] | [SPOJ PHONELST - Phone List](https://www.spoj.com/problems/PHONELST/) | is any number a prefix of another |
| [x] | [CF 4C - Registration system](https://codeforces.com/problemset/problem/4/C) — [solution](cf-betaground4d2c.cpp) | count per end node (1300) |

## Stage 2 — Counting on nodes / trie + DP

| Done | Problem | Idea |
| --- | --- | --- |
| [x] | [LC 211 - Design Add and Search Words](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | DFS on `.` wildcard |
| [ ] | [LC 2416 - Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/) | `cnt` of words passing each node |
| [ ] | [**CSES 1731 - Word Combinations**](https://cses.fi/problemset/task/1731) | `dp[i]` + walk trie from `i` — the classic |
| [ ] | [LC 139 - Word Break](https://leetcode.com/problems/word-break/) | same as CSES 1731, boolean |
| [ ] | [LC 472 - Concatenated Words](https://leetcode.com/problems/concatenated-words/) | Word Break per word |
| [ ] | [CF 271D - Good Substrings](https://codeforces.com/problemset/problem/271/D) | insert all suffixes, count new nodes (1800) |
| [ ] | [CF 1902E - Collapsing Strings](https://codeforces.com/problemset/problem/1902/E) | trie of reversed strings, sum LCP (1900) |
| [ ] | [CF 633C - Spy Syndrome 2](https://codeforces.com/problemset/problem/633/C) | reversed trie + DP reconstruct (1900) |
| [ ] | [LC 212 - Word Search II](https://leetcode.com/problems/word-search-ii/) | grid DFS guided by trie |
| [ ] | [CF 455B - A Lot of Games](https://codeforces.com/problemset/problem/455/B) | win/lose DP on trie nodes (1900) |

## Stage 3 — Binary (XOR) trie

| Done | Problem | Idea |
| --- | --- | --- |
| [ ] | [LC 421 - Maximum XOR of Two Numbers](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) | greedy go opposite bit |
| [ ] | [**CSES 1655 - Maximum Xor Subarray**](https://cses.fi/problemset/task/1655) | prefix xor + binary trie |
| [ ] | [CF 706D - Vasiliy's Multiset](https://codeforces.com/problemset/problem/706/D) | insert / erase with counters (1800) |
| [ ] | [CF 923C - Perfect Security](https://codeforces.com/problemset/problem/923/C) | min xor, erase used (1800) |
| [ ] | [LC 1707 - Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/) | offline sort queries |
| [ ] | [CF 1285D - Dr. Evil Underscores](https://codeforces.com/problemset/problem/1285/D) | recursion on trie split (1900) |
| [ ] | [CF 817E - Choosing The Commander](https://codeforces.com/problemset/problem/817/E) | count xor < L (2000) |
| [ ] | [LC 1803 - Count Pairs With XOR in a Range](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/) | count(< hi+1) − count(< lo) |
| [ ] | [CF 842D - Vitya and Strange Lesson](https://codeforces.com/problemset/problem/842/D) | mex under global xor (2000) |
| [ ] | [CF 1416C - XOR Inverse](https://codeforces.com/problemset/problem/1416/C) | inversions per bit via trie (2000) |
| [ ] | [CF 665E - Beautiful Subarrays](https://codeforces.com/problemset/problem/665/E) | count prefix xor ≥ k (2100) |
| [ ] | [CF 282E - Sausage Maximization](https://codeforces.com/problemset/problem/282/E) | prefix vs suffix xor (2200) |
| [ ] | [CF 979D - Kuro and GCD and XOR and SUM](https://codeforces.com/problemset/problem/979/D) | trie per divisor + min (2200) |
| [ ] | [CF 1720D1](https://codeforces.com/problemset/problem/1720/D1) / [D2 - Xor-Subsequence](https://codeforces.com/problemset/problem/1720/D2) | DP max over trie on `a[i]^i` (1800 / 2400) |
| [ ] | [CF 888G - Xor-MST](https://codeforces.com/problemset/problem/888/G) | Boruvka / merge subtrees (2300) |
| [ ] | [CF 1625D - Binary Spiders](https://codeforces.com/problemset/problem/1625/D) | highest bit grouping + trie (2300) |

## Stage 4 — Hard / Aho-Corasick (trie + failure links)

| Done | Problem | Idea |
| --- | --- | --- |
| [ ] | [LC 1032 - Stream of Characters](https://leetcode.com/problems/stream-of-characters/) | reversed trie (or Aho-Corasick) |
| [ ] | [LC 745 - Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/) | insert `suffix#word` |
| [ ] | [LC 336 - Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/) | reversed trie + palindrome check |
| [ ] | [CF 965E - Short Code](https://codeforces.com/problemset/problem/965/E) | small-to-large heaps on trie (2200) |
| [ ] | [**CSES 2102 - Finding Patterns**](https://cses.fi/problemset/task/2102) | Aho-Corasick |
| [ ] | [**CSES 2103 - Counting Patterns**](https://cses.fi/problemset/task/2103) | Aho-Corasick + count on fail tree |
| [ ] | [**CSES 2104 - Pattern Positions**](https://cses.fi/problemset/task/2104) | Aho-Corasick, first occurrence |
| [ ] | [CF 710F - String Set Queries](https://codeforces.com/problemset/problem/710/F) | binary grouping of Aho-Corasick (2400) |
| [ ] | [CF 778C - Peterson Polyglot](https://codeforces.com/problemset/problem/778/C) | trie merging (2500) |

---

### Notes

- CSES only has a few trie problems (1731, 1655, 2102–2104); the rest of the ladder is CF/LC.
- Binary trie for `int`: loop bits `30 → 0`; for `long long` use `62 → 0`.
- Size the node pool as `n * L + 1` (string) or `n * 31 + 1` (binary) to avoid `new` per node.
