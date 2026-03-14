#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define FOR3(i, a, b) for (ll i = a; i <= b; ++i)
#define FOR4(i, a, b) for (ll i = a; i >= b; --i)
// note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto& x : a)
#define jj "\n"

typedef long long ll;

void run_case() {
  int n;
  string pattern;  // The input pattern X: each char is 'a', 'b', or '?'
  cin >> n >> pattern;

  // -----------------------------------------------------------------------
  // T = "ababab..." (1-indexed: T[1]='a', T[2]='b', T[3]='a', ...)
  //   T[i] = 'a' if i is odd, 'b' if i is even.
  //
  // The generation algorithm repeatedly removes a char from either the left or right end of T and appends it to S.
  //
  // KEY INSIGHT: track `offset` = total number of times we picked from the
  // LEFT end of T.  After `i` picks with `offset` of them from the left:
  //   - left pointer:  l = 1 + offset  (position in T, 1-indexed)
  //   - right pointer: r = offset + (n - i)
  //   - T[l] = 'a' iff l is odd iff offset is even  (offset % 2 == 0)
  //   - T[l] = 'b' iff l is even iff offset is odd   (offset % 2 == 1)
  //
  // STATE: we track the SET of feasible `offset` values as a range [offset_lo, offset_hi] plus a parity constraint:
  //   parity == 0  =>  only EVEN offsets in [offset_lo, offset_hi] are valid
  //   parity == 1  =>  only ODD  offsets in [offset_lo, offset_hi] are valid
  //   parity == 2  =>  ALL integers in [offset_lo, offset_hi] are valid (both parities)
  //
  // Initially offset = 0, so: offset_lo = 0, offset_hi = 0, parity = 0.
  // -----------------------------------------------------------------------

  int offset_lo = 0, offset_hi = 0, parity = 0;
  bool possible = true;

  for (int i = 0; i < n && possible; i++) {
    char c = pattern[i];

    // `remaining` = n - i  characters left in T at this step.
    // When remaining is ODD:
    //   r - l = (n-i) - 1 = even  =>  r and l have the SAME parity
    //   =>  T[l] == T[r]  =>  BOTH ENDS GIVE THE SAME CHARACTER (forced).
    //   Character is 'a' if offset is even (parity=0), 'b' if offset is odd (parity=1).
    // When remaining is EVEN:
    //   r and l have DIFFERENT parity  =>  one end gives 'a', other gives 'b' (free choice).
    bool both_ends_same = (i + n) % 2 == 1;  // equivalent to (n - i) % 2 == 1

    if (c == '?') {
      // Any character is acceptable. Either end can be picked freely.
      // offset can stay (pick right) or increase by 1 (pick left).
      // => Range grows by 1 at the top, both parities become possible.
      offset_hi++;
      parity = 2;

    } else if (both_ends_same) {
      // Both ends give the same character, determined by offset parity:
      //   parity 0  (offset even => l odd)  =>  T[l] = 'a'
      //   parity 1  (offset odd  => l even) =>  T[l] = 'b'
      // We need to produce c.  required_parity is the parity that yields c.
      int required_parity = (c == 'a') ? 0 : 1;

      if (parity == required_parity) {
        // Current parity already correct.
        // After picking (either end), offset can stay or +1  =>  parity becomes mixed.
        offset_hi++;
        parity = 2;

      } else if (parity == 1 - required_parity) {
        // Current parity is the WRONG one; the character would be the opposite.
        possible = false;

      } else {  // parity == 2  (mixed range, both parities present)
        // Filter the range to only offsets with parity == required_parity.
        // Round offset_lo UP   to nearest value with required_parity.
        // Round offset_hi DOWN to nearest value with required_parity.
        int filtered_lo = offset_lo + ((offset_lo % 2) != required_parity ? 1 : 0);
        int filtered_hi = offset_hi - ((offset_hi % 2) != required_parity ? 1 : 0);

        if (filtered_lo > filtered_hi) {
          // No valid offset exists.
          possible = false;
          break;
        }
        // After picking (either end), each surviving offset p can become p or p+1.
        // Union of all {p, p+1} = contiguous range [filtered_lo, filtered_hi + 1].
        offset_lo = filtered_lo;
        offset_hi = filtered_hi + 1;
        parity = 2;
      }

    } else {
      // Both ends give DIFFERENT characters (one 'a', one 'b').  Free to choose.
      //
      // After picking 'a': we pick whichever end is at an ODD position.
      //   - If offset is even: l is odd (T[l]='a'), pick left  => offset becomes offset+1 (odd).
      //   - If offset is odd:  r is odd (T[r]='a'), pick right => offset stays (odd).
      //   => In BOTH cases the new offset is ODD  =>  next_parity = 1 for 'a'.
      //
      // After picking 'b': we pick the EVEN-position end.
      //   - If offset is odd:  l is even (T[l]='b'), pick left  => offset+1 (even).
      //   - If offset is even: r is even (T[r]='b'), pick right => offset stays (even).
      //   => In BOTH cases the new offset is EVEN  =>  next_parity = 0 for 'b'.
      int next_parity = (c == 'a') ? 1 : 0;

      // `shift_parity`: offsets with THIS parity will pick from the LEFT (offset += 1).
      // Offsets with next_parity will pick from the right (offset unchanged).
      int shift_parity = 1 - next_parity;

      if (parity == next_parity) {
        // All offsets already have the correct parity. They each pick from the right.
        // offset unchanged, parity stays next_parity.  (No variable update needed.)

      } else if (parity == shift_parity) {
        // All offsets have shift_parity; they each pick from the left (offset += 1).
        // The whole range shifts up by 1, parity flips to next_parity.
        offset_lo++;
        offset_hi++;
        parity = next_parity;

      } else {  // parity == 2  (mixed range)
        // Offsets with next_parity  => pick right, offset stays.
        // Offsets with shift_parity => pick left,  offset becomes offset+1 (= next_parity).
        // New set = { p : p has next_parity, offset_lo<=p<=offset_hi }
        //         ∪ { p+1 : p has shift_parity, offset_lo<=p<=offset_hi }
        // Both subsets produce values with next_parity.
        // This equals: next_parity values in [offset_lo, offset_hi+1].
        // => new_offset_lo = first next_parity value >= offset_lo
        // => new_offset_hi = last  next_parity value <= offset_hi+1
        //    But (offset_hi+1) has shift_parity iff offset_hi has next_parity, so:
        //    new_offset_hi = offset_hi + (offset_hi has shift_parity ? 1 : 0)
        int new_offset_lo = offset_lo + (offset_lo % 2 == shift_parity ? 1 : 0);
        int new_offset_hi = offset_hi + (offset_hi % 2 == shift_parity ? 1 : 0);
        offset_lo = new_offset_lo;
        offset_hi = new_offset_hi;
        parity = next_parity;
      }
    }
  }

  // Check that at least one feasible offset remains in the range.
  if (possible) {
    if (parity == 2) {
      // Dense range: non-empty iff lo <= hi.
      possible = (offset_lo <= offset_hi);
    } else {
      // Step-2 range: find the first value in [offset_lo, offset_hi] with
      // the required parity, and check it does not exceed offset_hi.
      int first_valid = offset_lo + ((offset_lo % 2) != parity ? 1 : 0);
      possible = (first_valid <= offset_hi);
    }
  }

  cout << (possible ? "YES" : "NO");
}

void run_with_t() {
  int t;
  cin >> t;
  while (t--) {
    run_case();
    cout << jj;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif  // ONLINE_JUDGE

  run_with_t();
  // run_case();
  return 0;
}
