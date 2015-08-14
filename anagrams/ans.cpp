/**
 * @file ans.cpp
 * @brief
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 * For example:
 *
 * Input:　　["tea","and","ate","eat","den"]
 *
 * Output:   ["tea","ate","eat"]
 *
 * Interface: vector<string>anagrams(vector<string>&strs);
 *
 * @version
 * @date 2015-05-30 11:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> result;
        if (strs.size() == 0)
            return result;

        map<string, int> hash;
        for (int i = 0; i < (int)strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (hash.find(tmp) != hash.end())
            {
                if (hash[tmp] != -1)
                {
                    result.push_back(strs[hash[tmp]]);
                    hash[tmp] = -1;
                }
                result.push_back(strs[i]);
            }
            else
            {
                hash[tmp] = i;
            }
        }

        return result;
    }
};

