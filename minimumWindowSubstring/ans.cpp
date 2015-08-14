/**
 * @file ans.cpp
 * @brief
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always
 * be only one unique minimum window in S.
 *
 * @version
 * @date 2015-06-11 15:44
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size())
            return "";

        string result;
        int stillNeed[256] = {0};
        int totalNeed[256] = {0};
        int found[256] = {0};
        int count = t.size();

        for (int i = 0; i < (int)t.size(); i++)
        {
            stillNeed[t[i]]++;
            totalNeed[t[i]]++;
        }

        int begin = 0;
        int end = 0;
        int minLength = s.size() + 1;
        int minStart = 0;
        for (; end < s.size(); end++)
        {
            found[s[end]]++;
            if (stillNeed[s[end]] > 0)
            {
                stillNeed[s[end]]--;
                count--;
            }

            if (count == 0)
            {
                for (; begin <= end; begin++)
                {
                    if (totalNeed[s[begin]])
                    {
                        if (minLength > (end - begin + 1))
                        {
                            minStart = begin;
                            minLength = end - begin + 1;
                        }

                        if (found[s[begin]] == totalNeed[s[begin]])
                        {
                            count++;
                            stillNeed[s[begin]]++;
                            found[s[begin]]--;
                            begin++;
                            break;
                        }
                    }
                    found[s[begin]]--;
                }
            }
        }

        return minLength == ((int)s.size() + 1) ? "" : s.substr(minStart, minLength);
    }
};

int main(int argc, char *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;

    cout << sol.minWindow(s, t) << endl;

    return 0;
}

