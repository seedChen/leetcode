/**
 * @file ans.cpp
 * @brief
 * Given a digit string, return all possible letter combinations that the number
 * could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * @version
 * @date 2015-05-08 14:32
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

const char* dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
    "wxyz"};

class Solution
{
private:

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.size() == 0)
            return result;

        if (digits.size() == 1)
        {
            const char* first = dict[digits[0] - '0'];
            for (int i = 0; i < strlen(first); ++i)
                result.push_back(string(first + i, 1));
            return  result;
        }

        vector<string> subRet = letterCombinations(digits.substr(1, digits.size() - 1));
        const char* first = dict[digits[0] - '0'];
        for (int i = 0; i < strlen(first); ++i)
        {
            for (int j = 0; j < subRet.size(); j++)
            {
                string s(first + i, 1);
                s.append(subRet[j]);
                result.push_back(s);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string t("23456");
    vector<string> ret = s.letterCombinations(t);
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << endl;
    return 0;
}
