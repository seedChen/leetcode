/**
 * @file ans.cpp
 * @brief
 * Given two integers n and k, return all possible combinations of k numbers out
 * of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 * @version
 * @date 2015-06-12 16:49
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    void helper(const vector<int>& numbers, vector<int>& path, int start, int k, vector<vector<int> >& result)
    {
        if (path.size() == path.capacity())
        {
            result.push_back(path);
            return;
        }

        for (int i = start; i < (int)numbers.size() - k + 1; i++)
        {
            path.push_back(numbers[i]);
            helper(numbers, path, i + 1, k - 1, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        if (n <= 0 || k <= 0 || n < k)
            return result;

        vector<int> numbers;
        numbers.reserve(n);
        vector<int> path;
        path.reserve(k);

        for (int i = 1; i <=n; i++)
            numbers.push_back(i);

        helper(numbers, path, 0, k, result);

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int> > ret = s.combine(4, 2);
    for (auto i : ret)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
