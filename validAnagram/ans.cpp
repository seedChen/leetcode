/**
 * @file ans.cpp
 * @brief
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * @version
 * @date 2015-08-12 14:57
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen != tlen)
            return false;

        int hash[256] = {0};
        for (int i = 0; i < slen; i++)
        {
            hash[s[i]]++;
        }

        for (int i = 0; i < tlen; i++)
        {
            if (hash[t[i]] > 0)
                hash[t[i]]--;
            else
                return false;
        }

        return true;
    }
};

