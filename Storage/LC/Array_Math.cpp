#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 7. Reverse Integer
 * =================================================================================================
 */

// INT_MAX = 2147483647 (2³¹ - 1)
// INT_MIN = -214748364
int reverse(int x) {
    if (x > INT_MAX or x < INT_MIN)
        return 0;

    int n = x;
    int rev = 0;
    while (n != 0) {
        int r = n % 10;
        // already greater than or the final pos
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && r > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && r < -8))
            return 0;

        rev = rev * 10 + r;
        n = n / 10;
    }
    return rev;
}

/**
 * =================================================================================================
 * 11. Container With Most Water
 * =================================================================================================
 */

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));

        if (height[left] < height[right])
            left++;
        else
            right--;
        // height[left] < height[right] ? left++ : right--;
    }

    return maxArea;
}

/**
 * =================================================================================================
 * 15. 3Sum
 * =================================================================================================
 */

/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

vector<vector<int>> solve(vector<int>& a) {
    vector<vector<int>> res;
    int n = a.size();

    if (n < 3)
        return res;

    sort(a.begin(), a.end());
    for (size_t i = 0; i < n - 2; ++i) {
        if (i > 0 && a[i] == a[i - 1])
            continue;  // Skip duplicates for 'i'

        int target = 0 - a[i];

        int l = i + 1, r = n - 1;

        while (l < r) {
            int sum = a[l] + a[r];
            if (sum < target) {
                l++;
                // Eliminates all pairs (current_l, anything)
            } else if (sum > target) {
                r++;
                // eliminate pairs (anything, current_r)
            } else {
                res.push_back({a[i], a[l], a[r]});

                while (l < r && a[l] == a[l + 1])
                    l++;
                while (l < r && a[r] == a[r - 1])
                    r--;

                l++, r--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = solve(a);
    for (const auto& triplet : res) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

/**
 * =================================================================================================
 * 50. Pow(x, n)
 * =================================================================================================
 */

// caculate power include negative
double myPow(double x, int n) {
    if (n == 1)
        return x;
    if (n == 0)
        return 1;
    if (n == -1)
        return 1.0 / x;

    double t = myPow(x, n / 2);
    if (n % 2 == 0)
        return t * t;
    else {
        if (n > 0)
            return t * t * x;
        else
            return t * t / x;
    }
}

int main() {
    cout << fixed << myPow(2, -2);
    return 0;
}

/**
 * =================================================================================================
 * 169. Majority Element
 * =================================================================================================
 */

// apply boyer-moore voting algorithm to find majority element

int majorityElement(vector<int>& a) {
    int n = a.size();

    int t = -1, count = 0;

    for (int i = 0; i < n; ++i) {
        if (count == 0) {
            t = a[i];
            count = 1;
        } else {
            if (a[i] == t)
                count++;
            else
                count--;
        }
    }

    int check = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == t)
            check++;
    }
    if (check > n / 2)
        return t;
    return -1;
}

int main() {
    vector<int> a = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(a);
    return 0;
}

/**
 * =================================================================================================
 * 233. Number of Digit One
 * =================================================================================================
 */

// c1: brute force
class Solution {
   public:
    int support1(long long x) {
        int count = 0;
        x = abs(x);
        while (x > 0) {
            if (x % 10 == 1)
                count++;
            x /= 10;
        }
        return count;
    }

    int support2(long long x) {
        string s = to_string(x);
        return count(s.begin(), s.end(), '1');
    }

    int countDigitOne(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += support1(i);
        return res;
    }
};
// Time Limit Exceeded

// c2: count per digit position, O(log n)
class Solution {
   public:
    int countDigitOne(int n) {
        long long res = 0;
        for (long long place = 1; place <= n; place *= 10) {
            long long high = n / (place * 10);  // digit above cur
            long long cur = (n / place) % 10;   // the digit at place
            long long low = n % place;          // digit below cur

            if (cur == 0)
                res += high * place;
            else if (cur == 1)
                res += high * place + low + 1;
            else
                res += (high + 1) * place;
        }
        return res;
    }
};

/**
 * =================================================================================================
 * 324. Wiggle Sort II
 * =================================================================================================
 */

/*

void wiggleSort(vector<int> &a)
{
    vector<int> res;

    sort(a.begin(), a.end());

    int t = 0, n = a.size(), l = 0, r = n - 1;

    while (t < n)
    {
        res.push_back(a[l++]);
        t++;

        if (t == n)
            break;
        res.push_back(a[r--]);
        t++;
    }

    a = res;
}
 has equal case so wrong
*/

//[4, 5, 5, 6] wrong
void wiggleSortWrong(vector<int>& a) {
    vector<int> res;

    sort(a.begin(), a.end());

    int n = a.size();
    int t;
    if (n % 2 == 0)
        t = n / 2;
    else
        t = n / 2 + 1;

    int t1 = 0, t2 = t, count = 0;
    while (count < n) {
        res.push_back(a[t1++]);
        count++;

        if (count == n)
            break;
        res.push_back(a[t2++]);
        count++;
    }
    a = res;
}

void wiggleSort(vector<int>& a) {
    int n = a.size();
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    int mid = (n - 1) / 2;

    int left = mid;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = sorted[left--];
        } else {
            a[i] = sorted[right--];
        }
    }
}

/**
 * =================================================================================================
 * 400. Nth Digit
 * =================================================================================================
 */

// 1-9  : 9  base case return that

// 10-99 : 90

// 100-999: 900

// 1000- 9999 : 9000
/*
9*1
90*2
900*3
9000*4
*/

int findNthDigit(int n) {
    // detect range
    int digit = 1, numOfNum = 9;

    while (n > digit * numOfNum) {
        n -= digit * numOfNum;
        digit++;
        numOfNum *= 10;
    }

    int pos = (n - 1) / digit;  // n minus first number/ digit
    int remainder = (n - 1) % digit;
    int start = (digit == 1) ? 1 : pow(10, digit - 1);  // startnumber

    string s = to_string(start + pos);
    return s[remainder] - '0';
}

int main() {
    int n = 11;
    cout << findNthDigit(n);
    return 0;
}

/**
 * =================================================================================================
 * 462. Minimum Moves to Equal Array Elements II
 * =================================================================================================
 */

// this one is medium oh my god i ran dom chooose i right:))

int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int t = nums[int(n / 2)];
    int res = 0;

    for (auto i : nums)
        res += abs(i - t);
    return res;
}

/**
 * =================================================================================================
 * 611. Valid Triangle Number
 * =================================================================================================
 */

int triangleNumberBruteForce(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // Only need to check this condition since array is sorted
                if (nums[i] + nums[j] > nums[k]) {
                    count++;
                }
            }
        }
    }
    return count;
}

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    // chose k and right as 2 valid number
    for (int k = 2; k < n; k++) {
        int left = 0, right = k - 1;

        while (left < right) {
            if (nums[left] + nums[right] > nums[k]) {
                // All pairs (left, left+1), (left, left+2), ..., (left, right)
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }
    return count;
}

/**
 * =================================================================================================
 * 868. Binary Gap
 * =================================================================================================
 */

int binaryGap(int n) {
    string s = "";

    int t = n;
    while (t > 0) {
        int r = t % 2;
        s = (char)('0' + r) + s;
        t /= 2;
    }

    // init string

    int res = 0;
    int start = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            if (start == -1) {
                start = i;
            } else {
                res = max(res, i - start);
                start = i;
            }
        }
    }
    return res;
}

int main() {
    cout << binaryGap(5);
    return 0;
}

/*
=== TYPICAL SIZES (Platform dependent) ===

COMMON 64-bit SYSTEM:
- char: 8 bits (1 byte)
- short: 16 bits (2 bytes)
- int: 32 bits (4 bytes)
- long: 64 bits (8 bytes) on Linux/Mac, 32 bits (4 bytes) on Windows
- long long: 64 bits (8 bytes)
- float: 32 bits (4 bytes)
- double: 64 bits (8 bytes)
- long double: 80/128 bits (varies by compiler)
- bool: 8 bits (1 byte, but only uses 1 bit logically)
- void*: 64 bits (8 bytes)

RANGES FOR SIGNED INTEGERS:
- char: -128 to 127
- short: -32,768 to 32,767
- int: -2,147,483,648 to 2,147,483,647
- long long: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

RANGES FOR UNSIGNED INTEGERS:
- unsigned char: 0 to 255
- unsigned short: 0 to 65,535
- unsigned int: 0 to 4,294,967,295
- unsigned long long: 0 to 18,446,744,073,709,551,615

GUARANTEED MINIMUMS (C++ Standard):
- char: at least 8 bits
- short: at least 16 bits
- int: at least 16 bits
- long: at least 32 bits
- long long: at least 64 bits

RELATIONSHIPS GUARANTEED BY STANDARD:
sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
sizeof(float) <= sizeof(double) <= sizeof(long double)
*/

int binaryGap(int n) {
    int res = 0;
    int start = -1;

    for (int i = 0; i < 32; ++i) {
        if ((n >> i) & 1) {  // Check if i-th bit is 1
            if (start != -1) {
                res = max(res, i - start);
            }
            start = i;
        }
    }
    return res;
}

/**
 * =================================================================================================
 * 1262. Greatest Sum Divisible by Three
 * =================================================================================================
 */

int maxSumDivThree(vector<int>& a) {
    vector<int> one, two;
    int res = 0;
    for (auto i : a) {
        res += i;
        if (i % 3 == 1) {
            one.push_back(i);
        } else if (i % 3 == 2) {
            two.push_back(i);
        }
    }

    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    int r = res % 3;

    if (r == 0)
        return res;

    if (r == 1) {
        // remove smallest r=1,
        int opt1 = (!one.empty()) ? one[0] : INT_MAX;
        // remove 2 smallest r=2  => 4
        int opt2 = (two.size() >= 2) ? two[0] + two[1] : INT_MAX;
        res -= min(opt1, opt2);
    } else {  // r=2
        // remove smalleset r2
        int opt1 = (!two.empty()) ? two[0] : INT_MAX;
        // remove 2 smallest r1
        int opt2 = (one.size() >= 2) ? one[0] + one[1] : INT_MAX;
        res -= min(opt1, opt2);
    }

    return res;
}
int main() {
    return 0;
}

/**
 * =================================================================================================
 * 1267. Count Servers that Communicate
 * =================================================================================================
 */

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }

        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1))
                    res++;
            }

        return res;
    }
};

/**
 * =================================================================================================
 * 2211. Count Collisions on a Road
 * =================================================================================================
 */

int countCollisions(string directions) {
    int n = directions.size();
    int left = 0, right = n - 1;

    while (left < n && directions[left] == 'L')
        left++;
    while (right >= 0 && directions[right] == 'R')
        right--;

    int collisions = 0;
    for (int i = left; i <= right; i++) {
        if (directions[i] != 'S')
            collisions++;
    }

    return collisions;
}

/**
 * =================================================================================================
 * 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
 * =================================================================================================
 */

int minOperations(vector<int>& nums) {
    int n = nums.size(), minLen = INT_MAX;

    int countOnes = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1)
            countOnes++;
    }
    if (countOnes > 0)
        return n - countOnes;

    for (int i = 0; i < n; ++i) {
        int tmp = nums[i];
        for (int j = i + 1; j < n; ++j) {
            tmp = __gcd(tmp, nums[j]);

            if (tmp == 1) {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }

    if (minLen == INT_MAX)
        return -1;
    return minLen + n - 2;
}

/**
 * =================================================================================================
 * 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
 * =================================================================================================
 */

class Solution {
   public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                inc = inc + 1, dec = 1;  // break dec subarray
            else if (nums[i] < nums[i - 1])
                dec = dec + 1, inc = 1;  // break inc subarray
            else
                inc = dec = 1;  // equal breaks both
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};

// i missunderstanding so i create another version harder is not continuous array, like LCS
class Solution {
   public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        // dd1 increase, dd2 deccrease
        vector<int> dd1(n, 1), dd2(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])  // increase
                    dd1[i] = max(dd1[i], dd1[j] + 1);
                if (nums[j] > nums[i])  // decrease
                    dd2[i] = max(dd2[i], dd2[j] + 1);
            }
        }

        for (auto i : dd1) cout << i << " ";
        cout << endl;
        for (auto i : dd2) cout << i << " ";

        int res = 1;
        for (int i = 0; i < n; ++i)
            res = max({res, dd1[i], dd2[i]});
        return res;
    }
};
