#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 3. Longest Substring Without Repeating Characters
 * =================================================================================================
 */

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;  // Map to store the last seen index of each character
    int res = 0;
    int l = 0;  // Left pointer of the sliding window

    for (int r = 0; r < s.length(); r++) {
        // r is the right pointer of the sliding window
        char currentChar = s[r];

        // If we have seen the character before, move the left pointer
        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= l) {
            // Move the left pointer to one past the previous index of the current character
            l = lastIndex[currentChar] + 1;
        }

        // Update the last seen index of the current character
        lastIndex[currentChar] = r;

        // Update the result with the size of the current window
        res = max(res, r - l + 1);
    }

    return res;
}

/**
 * =================================================================================================
 * 5. Longest Palindromic Substring
 * =================================================================================================
 */

/*
Input: s = "babad"
Output: "bab"
*/

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0)
        return "";

    int start = 0;
    int maxLen = 1;

    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    };

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(i, i);  // case string has the middle character

        int len2 = expandAroundCenter(i, i + 1);  // case string not has the middle character

        int len = max(len1, len2);

        if (len > maxLen) {
            maxLen = len;
            start = i - (maxLen - 1) / 2;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s);
    return 0;
}

/**
 * =================================================================================================
 * 6. Zigzag Conversion
 * =================================================================================================
 */

string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    int n = s.length();
    string res = "";

    int i = 0;
    int cycleLen = 2 * numRows - 2;

    // first row
    for (int i = 0; i < n; i += cycleLen) {
        res += s[i];
    }

    // mid
    for (int k = 1; k < numRows - 1; k++) {
        for (int i = k; i < n; i += cycleLen) {
            res += s[i];
            int next = i + cycleLen - 2 * k;
            if (next < n) {
                res += s[next];
            }
        }
    }

    // last row

    for (int i = numRows - 1; i < n; i += cycleLen) {
        res += s[i];
    }
    return res;
}

/**
 * =================================================================================================
 * 8. String to Integer (atoi)
 * =================================================================================================
 */

int myAtoi(string s) {
    int res = 0, sign = 1;
    int n = s.length(), i = 0;

    // space
    while (i < n && s[i] == ' ')
        i++;

    // sign
    if (i < n)
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

    // zero
    while (i < n && s[i] == '0')
        i++;

    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
        // overflow
        if (res > (INT_MAX - digit) / 10)
            return (sign == 1) ? INT_MAX : INT_MIN;

        res = res * 10 + digit;
        i++;
    }
    return res * sign;
}

/**
 * =================================================================================================
 * 151. Reverse Words in a String
 * =================================================================================================
 */

/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

string reverseWords(string s) {
    int n = s.size();
    reverse(s.begin(), s.end());

    int finalIndex = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            // space
            if (finalIndex != 0) s[finalIndex++] = ' ';
            int wordStart = finalIndex;
            int j = i;

            while (j < n && s[j] != ' ') {
                s[finalIndex++] = s[j++];
            }

            // wordstart not word start -1 as wordstart start from 0 (s.begin()+0 fo ex)
            reverse(s.begin() + wordStart, s.begin() + finalIndex);
            // j is space;
            i = j;
        }
    }

    s.resize(finalIndex);
    return s;
}

int main() {
    string s = "the sky is blue";
    s = reverseWords(s);
    cout << s;
    return 0;
}

/**
 * =================================================================================================
 * 179. Largest Number
 * =================================================================================================
 */

static bool comp(string a, string b) {
    // return a<b; // 10 > 2
    return a + b > b + a;
}
string largestNumber(vector<int>& nums) {
    vector<string> s;
    for (auto i : nums) {
        s.push_back(to_string(i));
    }

    sort(s.begin(), s.end(), comp);

    // sort(s.begin(), s.end(), [](string &a, string &b)
    //      { return a + b > b + a; });

    // edge case
    if (s[0] == "0")
        return "0";

    string res = "";
    for (auto i : s)
        res += i;

    return res;
}

int main() {
    // vector<int> a = {3, 30, 34, 5, 9};
    vector<int> a = {10, 2};
    cout << largestNumber(a);

    return 0;
}

/**
 * =================================================================================================
 * 273. Integer to English Words
 * =================================================================================================
 */

/*
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

string basecaseHelper(int num) {
    // num< 1000
    string digit1[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string digitTeen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string digit2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string res = "";

    if (num > 99) {
        // has hunred in num
        res += digit1[num / 100] + " Hundred ";
    }

    num %= 100;

    // teen
    if (num < 20 && num > 9) {
        res += digitTeen[num - 10] + " ";
    } else {
        if (num >= 20)
            res += digit2[num / 10] + " ";

        num %= 10;

        // 1 digit handle
        if (num > 0)
            res += digit1[num] + " ";
    }

    return res;
}

string intToEnglishWords(int num) {
    if (num == 0)
        return "Zero";

    string big[] = {"Thousand", "Million", "Billion"};
    string res = basecaseHelper(num % 1000);

    // iter through thousand mil and bil (reverse)
    for (int i = 0; i < 3; ++i) {
        if (num > 0 && num % 1000 > 0) {
            res = basecaseHelper(num % 1000) + big[i] + " " + res;
        }
        num /= 1000;
    }

    return res;
}

int main() {
    int num = 1234567;
    cout << intToEnglishWords(num);
    return 0;
}

/**
 * =================================================================================================
 * 402. Remove K Digits
 * =================================================================================================
 */

string removeKdigits(string num, int k) {
    stack<char> st;
    for (auto i : num) {
        while (!st.empty() && i < st.top() && k > 0) {
            k--;
            st.pop();
        }
        st.push(i);
    }

    while (k != 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    // find
    // find first not of
    // find first of
    // find last not of
    // find last of
    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos)
        res = "0";
    else
        res = res.substr(pos);

    return res;
}

// faster version
string removeKdigits1(string num, int k) {
    string result = "";

    for (char digit : num) {
        while (!result.empty() && result.back() > digit && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }

    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }

    size_t pos = result.find_first_not_of('0');
    if (pos == string::npos)
        return "0";

    result = result.substr(pos);
    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;

    cout << removeKdigits(num, k);
    return 0;
}

/**
 * =================================================================================================
 * 420. Strong Password Checker
 * =================================================================================================
 */

int strongPasswordChecker(string password) {
    int n = password.length();

    bool digit = false, upper = false, lower = false;

    // for (auto i : password)
    // {
    //   if (i >= '0' && i <= '9')
    //     digit = true;
    //   if (i >= 'A' && i <= 'Z')
    //     upper = true;
    //   if (i >= 'a' && i <= 'z')
    //     lower = true;
    // }

    for (char c : password) {
        if (islower(c))
            lower = true;
        if (isupper(c))
            upper = true;
        if (isdigit(c))
            digit = true;
    }

    int missing = !lower + !upper + !digit;

    int change = 0, one = 0, two = 0;

    for (int i = 2; i < n; ++i) {
        if (password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
            int j = i;
            // Find the end of this repeating sequence
            while (j < n && password[j] == password[i - 2]) {
                j++;
            }
            int len = j - (i - 2);

            change += len / 3;  // Each 'aaa' sequence needs one replacement

            if (len % 3 == 0)
                one++;  //  'aaa', 'aaaaaa'
            else if (len % 3 == 1)
                two++;  //  'aaaa', 'aaaaaaa'

            i = j - 1;  // Move index to the end of the processed sequence
        }
    }

    // Case 1: Password is too short
    if (n < 6) {
        return max(missing, 6 - n);
    }
    // Case 2: Password length is in the ideal range
    else if (n <= 20) {
        return max(missing, change);
    }
    // Case 3: Password is too long
    else {
        int del = n - 20;  // Number of characters we must delete to reach max length of 20.
        /*
        KEY INSIGHT: Deletions help us fix repeating sequences!
        Instead of: Delete + Replace, we can sometimes just: Delete only!

        delete 2 char "aaaa" → "aa"
        aaaa → aaba (1 operation)

        Category 1: length % 3 == 0 ( "aaa", "aaa aaa")
        - "aaa"-> aba needs 1 replacement
        - "aaa" → "aa" delete (1)
        Category 2: length % 3 == 1 (like "aaaa", "aaaaaaa")
        - "aaaa" needs 1 replacement
        - Delete 2 chars: "aaaa" → "aa"
        Category 3: length % 3 == 2 (like "aaaaa", "aaaaaaaa")
        - "aaaaa" needs 1 replacement
        - Delete 3 chars: "aaaaa" → "aa"
        */

        // Priority 1: Use 1 deletion to fix a 'len % 3 == 0' sequence. Most efficient.
        change -= min(del, one);  // instead of changing the char, we can just del where I need to del 1 chars

        // Priority 2: Use 2 deletions to fix a 'len % 3 == 1' sequence.
        change -= min(max(0, del - one), two * 2) / 2;

        // Priority 3: Use remaining deletions. Any 3 deletions can fix one repeat.
        change -= max(0, del - one - two * 2) / 3;

        // mandatory deletions + remaining fixes.
        return del + max(missing, change);
    }
}

int main() {
    string password = "aA1";
    cout << strongPasswordChecker(password);
    return 0;
}

/**
 * =================================================================================================
 * 466. Count The Repetitions
 * =================================================================================================
 */

/*
PASS BUT STILL A LOW PERFORMANCE SOLUTION
Example 1:

Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
Output: 2
Example 2:

Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
Output: 1
*/

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.length(), l2 = s2.length();

    int res = 0;
    int t = 0;

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < l1; ++j) {
            if (s1[j] == s2[t]) {
                t++;
                // if (t == l2 - 1)
                if (t == l2) {
                    res++;
                    t = 0;
                }
            }
        }

    return res / n2;
}

int main() {
    string s1 = "acb", s2 = "ab";
    int n1 = 4, n2 = 2;

    cout << getMaxRepetitions(s1, n1, s2, n2);
    return 0;
}

/**
 * =================================================================================================
 * 944 + 955 + 960. Delete Columns to Make Sorted I / II / III
 * =================================================================================================
 */

int minDeletionSize944(vector<string>& strs) {
    int r = strs.size();
    int c = strs[0].length();

    int res = 0;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r - 1; ++j) {
            if (strs[j][i] > strs[j + 1][i]) {
                res++;
                break;
            }
        }
    }
    return res;
}

int minDeletionSize995(vector<string>& strs) {
    int r = strs.size();
    int c = strs[0].length();
    int res = 0;

    // sorted[i] = true: strs[i] đã < strs[i+1] khi duyệt đến cột hiện tại
    vector<bool> sorted(r - 1, false);

    for (int i = 0; i < c; ++i) {
        bool needDelete = false;         // do we need to delete this column?
        for (int j = 0; j < r - 1; ++j)  // hàng
        {
            if (!sorted[j] && strs[j][i] > strs[j + 1][i]) {
                needDelete = true;
                break;
            }
        }
        if (needDelete)
            res++;
        else  // cột này không bị xóa
        {
            for (int row = 0; row < r - 1; ++row) {
                if (strs[row][i] < strs[row + 1][i])
                    sorted[row] = true;
            }
        }
    }

    return res;
}

// 960
int minDeletionSize960(vector<string>& strs) {
    int r = strs.size();
    int c = strs[0].length();

    vector<int> tmp(c, 1);

    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < i; ++j) {
            bool canPlaceAfter = true;
            for (int k = 0; k < r; ++k) {
                if (strs[k][i] < strs[k][j]) {
                    canPlaceAfter = false;
                    break;
                }
            }

            if (canPlaceAfter)

                tmp[i] = max(tmp[j] + 1, tmp[i]);
        }
    }

    int res = *max_element(tmp.begin(), tmp.end());
    return c - res;
}

/**
 * =================================================================================================
 * 1513. Number of Substrings With Only 1s
 * =================================================================================================
 */

const int MOD = 1e9 + 7;

int numSub(string s) {
    vector<int> tmp;

    long long t = s[0] == '0' ? 0 : 1;
    for (auto i = 1; i < s.size(); ++i) {
        if (s[i] == '1')
            t++;
        else {
            if (t > 0)
                tmp.push_back(t);
            t = 0;
        }
    }

    if (t > 0)
        tmp.push_back(t);

    long long res = 0;
    for (long long n : tmp)
        res = (res + n * (n + 1) / 2) % MOD;

    // caculate base on 2^n?
    return res;
}

int main() {
    string s = "0110111";
    cout << numSub(s) << endl;
    return 0;
}

// sum 1+2+...+n = n(n+1)/2
int numSub1(string s) {
    const int MOD = 1e9 + 7;
    long long res = 0;
    int count = 0;

    for (char c : s) {
        if (c == '1') {
            count++;
            res = (res + count) % MOD;
        } else {
            count = 0;
        }
    }

    return res;
}

/**
 * =================================================================================================
 * 1930. Unique Length-3 Palindromic Subsequences
 * =================================================================================================
 */

int countPalindromicSubsequence(string s) {
    int n = s.length();
    int res = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        int first = -1, last = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        // has middle -> has palindrome
        if (first != -1 && last > first) {
            unordered_set<char> t;
            for (int i = first + 1; i < last; ++i)
                t.insert(s[i]);
            res += t.size();
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    cout << countPalindromicSubsequence(s) << endl;
    return 0;
}
