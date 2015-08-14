/**
 * @file ans.cpp
 * @brief
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 * @version
 * @date 2015-05-17 19:22
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <unordered_map>

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> result;
        int totalWordsLength = words.size() * words.begin()->size();
        if (s.size() == 0 || words.size() == 0 || words.begin()->size() == 0
                || (int)s.size() < totalWordsLength)
            return result;

        unordered_map<string, int> originDic;
        for (int i = 0; i < (int)words.size(); ++i)
        {
            originDic[words[i]]++;
        }

        int step = words.begin()->size();
        for (int i = 0; i < (int)words.begin()->size(); ++i)
        {
            unordered_map<string, int> dic(originDic);
            int j = i;
            int k = i;
            while (k  <= (int)s.size() - step)
            {
                string kNextWord = s.substr(k, step);
                if (dic.find(kNextWord) != dic.end())
                {
                    if (dic[kNextWord] > 0)
                    {
                        dic[kNextWord]--;
                    }
                    else
                    {
                        while (1)
                        {
                            string jNextWord = s.substr(j, step);
                            if (jNextWord == kNextWord)
                            {
                                j += step;
                                break;
                            }

                            dic[jNextWord]++;
                            j += step;
                        }
                    }
                }
                else
                {
                    while (j != k)
                    {
                        string jNextWord = s.substr(j, step);
                        dic[jNextWord]++;
                        j += step;
                    }
                    j += step;
                }

                k += step;
                if (k - j == totalWordsLength)
                    result.push_back(j);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "aaaaaaaa";
    vector<string> v;
    v.push_back(string("aa"));
    v.push_back(string("aa"));
    v.push_back(string("aa"));
    vector<int> ret = s.findSubstring(str, v);
    for (auto i : ret)
        cout << i << endl;

    return 0;
}
