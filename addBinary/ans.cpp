/**
 * @file ans.cpp
 * @brief
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 * @version
 * @date 2015-06-09 17:47
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        string result;

        while (i >= 0 && j >= 0)
        {
            int sum = a[i] - '0' + b[j] - '0' + c;
            result.push_back(sum % 2 + '0');
            c = sum / 2;

            i--;
            j--;
        }

        while (i >= 0)
        {
            int sum = a[i] - '0' + c;
            result.push_back(sum % 2 + '0');
            c = sum / 2;
            i--;
        }

        while (j >= 0)
        {
            int sum = b[j] - '0' + c;
            result.push_back(sum % 2 + '0');
            c = sum / 2;
            j--;
        }

        if (c)
            result.push_back('1');

        reverse(result.begin(), result.end());

        return result;
    }
};

