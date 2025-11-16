#include <bits/stdc++.h>
using namespace std;

int strongPasswordChecker(string password)
{
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

    for (char c : password)
    {
        if (islower(c))
            lower = true;
        if (isupper(c))
            upper = true;
        if (isdigit(c))
            digit = true;
    }

    int missing = !lower + !upper + !digit;

    int change = 0, one = 0, two = 0;

    for (int i = 2; i < n; ++i)
    {
        if (password[i] == password[i - 1] && password[i - 1] == password[i - 2])
        {
            int j = i;
            // Find the end of this repeating sequence
            while (j < n && password[j] == password[i - 2])
            {
                j++;
            }
            int len = j - (i - 2);

            change += len / 3; // Each 'aaa' sequence needs one replacement

            if (len % 3 == 0)
                one++; //  'aaa', 'aaaaaa'
            else if (len % 3 == 1)
                two++; //  'aaaa', 'aaaaaaa'

            i = j - 1; // Move index to the end of the processed sequence
        }
    }

    // Case 1: Password is too short
    if (n < 6)
    {
        return max(missing, 6 - n);
    }
    // Case 2: Password length is in the ideal range
    else if (n <= 20)
    {
        return max(missing, change);
    }
    // Case 3: Password is too long
    else
    {
        int del = n - 20; // Number of characters we must delete to reach max length of 20.
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
        change -= min(del, one); // instead of changing the char, we can just del where I need to del 1 chars

        // Priority 2: Use 2 deletions to fix a 'len % 3 == 1' sequence.
        change -= min(max(0, del - one), two * 2) / 2;

        // Priority 3: Use remaining deletions. Any 3 deletions can fix one repeat.
        change -= max(0, del - one - two * 2) / 3;

        // mandatory deletions + remaining fixes.
        return del + max(missing, change);
    }
}

int main()
{
    string password = "aA1";
    cout << strongPasswordChecker(password);
    return 0;
}