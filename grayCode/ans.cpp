/**
 * @file ans.cpp
 * @brief
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.]
 *
 * @version
 * @date 2015-06-17 11:05
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        if (n < 0)
            return result;
        result.push_back(0);
        if (n == 0)
            return result;

        result.push_back(1);
        for (int i = 1; i < n; i++)
        {
            for (int j = result.size() - 1; j >= 0; j--)
            {
                result.push_back(result[j] + pow(2, i));
            }
        }

        return result;
    }
};

