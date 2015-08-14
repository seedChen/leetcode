/**
 * @file ans.cpp
 * @brief
 * Given a string, find the length of the longest substring without repeating
 * characters. For example, the longest substring without repeating letters for
 * "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
 * is "b", with the length of 1.
 *
 * @version
 * @date 2015-04-14 09:47
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int length = s.size();
        int maxSubLength = 0;
        bool exists[256] = {false};

        while (j < length)
        {
            if (exists[s[j]])
            {
                maxSubLength = max(maxSubLength, j-i);
                while (s[i] != s[j])
                {
                    exists[s[i]] = false;
                    ++i;
                }
                ++i;
            }
            exists[s[j]] = true;
            ++j;
        }
        maxSubLength = max(maxSubLength, j-i);

        return maxSubLength;
    }
};

int main(int argc, char *argv[])
{
    string s1("abcabcbb");
    string s2("bbbbb");
    string s3("tmmzuxt");
    Solution s;
    cout << s.lengthOfLongestSubstring(s1) << endl;
    cout << s.lengthOfLongestSubstring(s2) << endl;
    cout << s.lengthOfLongestSubstring(s3) << endl;
    return 0;
}

