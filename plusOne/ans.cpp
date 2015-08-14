/**
 * @file ans.cpp
 * @brief
 * Given a non-negative number represented as an array of digits, plus one to
 * the number.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 *
 * @version
 * @date 2015-05-09 14:09
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> result;
        if (0 == digits.size())
            return result;

        int c = 1;
        for (int i = digits.size() - 1; i > -1; i--)
        {
            if (c + digits[i] == 10)
            {
                digits[i] = 0;
                c = 1;
            }
            else
            {
                digits[i] += c;
                c = 0;
                return digits;
            }
        }
        if (c == 1)
        {
            result.push_back(c);
        }
        for(int i = 0; i < digits.size(); i++)
        {
            result.push_back(digits[i]);
        }

        return result;
    }
};

