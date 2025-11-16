/*
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include <bits/stdc++.h>
using namespace std;

string basecaseHelper(int num)
{
    // num< 1000
    string digit1[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string digitTeen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string digit2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string res = "";

    if (num > 99)
    {
        // has hunred in num
        res += digit1[num / 100] + " Hundred ";
    }

    num %= 100;

    // teen
    if (num < 20 && num > 9)
    {
        res += digitTeen[num - 10] + " ";
    }
    else
    {
        if (num >= 20)
            res += digit2[num / 10] + " ";

        num %= 10;

        // 1 digit handle
        if (num > 0)
            res += digit1[num] + " ";
    }

    return res;
}

string intToEnglishWords(int num)
{

    if (num == 0)
        return "Zero";

    string big[] = {"Thousand", "Million", "Billion"};
    string res = basecaseHelper(num % 1000);

    // iter through thousand mil and bil (reverse)
    for (int i = 0; i < 3; ++i)
    {
        if (num > 0 && num % 1000 > 0)
        {
            res = basecaseHelper(num % 1000) + big[i] + " " + res;
        }
        num /= 1000;
    }

    return res;
}

int main()
{
    int num = 1234567;
    cout << intToEnglishWords(num);
    return 0;
}