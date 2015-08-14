/**
 * @file ans.cpp
 * @brief
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 * @version
 * @date 2015-06-03 16:33
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string result = "";
        if (n <= 0 || k <= 0)
            return result;

        vector<int> nums(n);
        int factorial = 1;
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
            factorial *= (i + 1);
        }

        k--;
        for(int i = 0 ; i < n; i++)
        {
            factorial = factorial / (n - i);
            int selected = k / factorial;
            result += ('0' + nums[selected]);

            // excellent! we only need to move elements forward.
            for(int j = selected; j < n - i - 1; j++)
                nums[j] = nums[j + 1];
            k = k % factorial;
        }

        return result;
    }
};

