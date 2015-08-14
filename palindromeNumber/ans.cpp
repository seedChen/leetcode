/**
 * @file ans.cpp
 * @brief
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * @version
 * @date 2015-05-02 12:57
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int len = 1;
        int tmpX = x;

        tmpX /= 10;
        while(tmpX != 0)
        {
            len *= 10;
            tmpX /= 10;
        }

        while(x != 0)
        {
            int left = x / len;
            int right = x % 10;

            if (left != right)
                return false;

            x = (x % len) / 10;
            len /= 100;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    int x1 = 1221;
    int x2 = 12121;
    int x3 = 1234;

    Solution s;
    cout << s.isPalindrome(x1) << endl;
    cout << s.isPalindrome(x2) << endl;
    cout << s.isPalindrome(x3) << endl;

    return 0;
}
