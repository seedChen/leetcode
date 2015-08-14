/**
 * @file ans.cpp
 * @brief
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, and there exists one
 * unique longest palindromic substring.
 *
 * @version
 * @date 2015-04-16 10:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t len = s.size();
        int start = 0;
        int max = 1;

        bool flags[len][len];
        for (size_t i = 0; i < len; i++)
            for (size_t j = 0; j < len; j++)
                if(i >= j)
                    flags[i][j] = true;
                else
                    flags[i][j] = false;

        for (int j = 1; j < (int)len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if(s[i] == s[j])
                {
                    flags[i][j] = flags[i + 1][j - 1];
                    if ((flags[i + 1][j - 1] == true) && (j - i + 1 > max))
                    {
                        max = j - i + 1;
                        start = i;
                    }
                }
                else
                    flags[i][j] = false;
            }
        }

        return s.substr(start, max);
    }
};

int main(int argc, char *argv[])
{
    string exam("ababbbbaaacccabbaccc");
    Solution s;
    cout << s.longestPalindrome(exam) << endl;;
    return 0;
}
