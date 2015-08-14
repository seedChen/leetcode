/**
 * @file ans.cpp
 * @brief
 * Implement atoi to convert a string to an integer.
 *
 * @version
 * @date 2015-05-02 12:56
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        if (0 == str.size())
            return 0;

        int firstCharIdx = 0;
        for (firstCharIdx = 0; firstCharIdx < str.size(); ++firstCharIdx)
        {
            if (str[firstCharIdx] != ' ')
                break;
        }
        if (firstCharIdx == str.size())
            return 0;

        bool minus = false;
        int firstNonzeroNumIdx = 0;
        if (str[firstCharIdx] == '+')
        {
            minus = false;
            firstNonzeroNumIdx = firstCharIdx + 1;
        }
        else if(str[firstCharIdx] == '-')
        {
            minus = true;
            firstNonzeroNumIdx = firstCharIdx + 1;
        }
        else
        {
            firstNonzeroNumIdx = firstCharIdx;
        }

        if (str.size() == firstNonzeroNumIdx)
            return 0;
        for (; firstNonzeroNumIdx < str.size(); ++firstNonzeroNumIdx)
        {
            if (str[firstNonzeroNumIdx] < '0' || str[firstNonzeroNumIdx] > '9')
                return 0;
            else if (str[firstNonzeroNumIdx] == '0')
                continue;
            else
                break;
        }
        if (str.size() == firstNonzeroNumIdx)
            return 0;

        long long result = str[firstNonzeroNumIdx] - '0';
        for (int numIdx = firstNonzeroNumIdx + 1; numIdx < str.size(); ++numIdx)
        {
            if (str[numIdx] >= '0' && str[numIdx] <= '9')
            {
                result = result * 10 + (str[numIdx] - '0');
                if (!minus && result > (int)0x7FFFFFFF)
                    return (int)0x7FFFFFFF;
                else if (minus && (-result) < (int)0x80000000)
                    return (int)0x80000000;
            }
            else
                break;
        }

        if (minus)
            return (int)(0 - result);
        else
            return (int)result;
    }
};

int main(int argc, char *argv[])
{
    // string str1("123456");
    // string str2("-654321");
    // string str3("010");
    string str4("-2147483649");
    Solution s;

    // cout << s.myAtoi(str1) << endl;
    // cout << s.myAtoi(str2) << endl;
    // cout << s.myAtoi(str3) << endl;
    cout << s.myAtoi(str4) << endl;

    return 0;
}

