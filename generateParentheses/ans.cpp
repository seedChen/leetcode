/**
 * @file ans.cpp
 * @brief
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * @version
 * @date 2015-05-15 12:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
private:
    void doGenerateParenthesis(int n, int nLeftPar, string combination, vector<string>& result)
    {
        if (nLeftPar < 0)
            return;
        if (combination.size() == 2 * n) 
        {
            if (nLeftPar == 0)
                result.push_back(combination);
            return;
        }

        doGenerateParenthesis(n, nLeftPar + 1, combination + '(', result);

        doGenerateParenthesis(n, nLeftPar - 1, combination + ')', result);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (n < 1)
            return result;

        string combination;
        doGenerateParenthesis(n, 0, combination, result);

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> ret;

    ret = s.generateParenthesis(3);

    for (auto s : ret)
        cout << s << endl;

    return 0;
}
