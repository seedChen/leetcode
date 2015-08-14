/**
 * @file ans.cpp
 * @brief
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has
 * length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 *
 * @version
 * @date 2015-05-19 11:25
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
            return 0;

        stack<int> stack;
        stack.push(-1);
        int maxLen = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            char c = s[i];
            if (c == '(')
            {
                stack.push(i);
            }
            else if (c == ')')
            {
                if (stack.size() > 1)
                {
                    stack.pop();
                    int tmp = stack.top();
                    maxLen = max(maxLen, i - tmp);
                }
                else
                {
                    stack.pop();
                    stack.push(i);
                }
            }
        }

        return maxLen;
    }
};

