/**
 * @file ans.cpp
 * @brief
 * Given a positive integer, return its corresponding column title as appear
 * in an Excel sheet.
 *
 * For example:
 *
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB
 *
 * @version
 * @date 2015-08-19 15:22
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string result;

    void helper(int n)
    {
        if (n <= 0)
            return;
        int x = n / 26;
        int y = n % 26;
        if (y == 0)
        {
            if (x > 1)
            {
                helper(x - 1);
                result.push_back('Z');
            }
            else
            {
                result.push_back('Z');
                return;
            }
        }
        else
        {
            helper(x);
            result.push_back('A' + y - 1);
        }
    }

public:
    string convertToTitle(int n) {
        if (n <= 0)
            return result;

        helper(n);
        return result;
    }
};

int main(int argc, char *argv[])
{
    {
    Solution s;
    cout << s.convertToTitle(26) << endl;
    }
    {
    Solution s;
    cout << s.convertToTitle(1) << endl;
    }
    {
    Solution s;
    cout << s.convertToTitle(27) << endl;
    }
    {
    Solution s;
    cout << s.convertToTitle(52) << endl;
    }
    Solution s;
    cout << s.convertToTitle(53) << endl;
    return 0;
}

