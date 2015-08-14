/**
 * @file ans.cpp
 * @brief
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * @version
 * @date 2015-04-17 21:24
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <stdexcept>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long result = 0;
        bool minus = false;
        if (x == (int)0x80000000)
            return 0;
        if (x < 0)
        {
            x = -x;
            minus = true;
        }

        while (x)
        {
            int last = x % 10;
            x = x / 10;
            result = result * 10 + last;
        }

        if (minus)
            result = -result;

        if (result < (int)0x80000000 || result > (int)0x7FFFFFFF)
            return 0;

        return result;
    }
};

int main(int argc, char *argv[])
{
    int x1 = 123;
    int x2 = -123;
    int x3 = 1534236469;
    int x4 = -1563847412;

    Solution s;

    cout << s.reverse(x1) << endl;
    cout << s.reverse(x2) << endl;
    cout << s.reverse(x3) << endl;
    cout << s.reverse(x4) << endl;

    return 0;
}
