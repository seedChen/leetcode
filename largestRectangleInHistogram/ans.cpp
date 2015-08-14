/**
 * @file ans.cpp
 * @brief
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 *
 * Above is a histogram where width of each bar is 1, given
 * height = [2,1,5,6,2,3].
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 *
 * @version
 * @date 2015-06-15 11:40
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& height)
    {
        vector<int> s;
        //插入高度为0的bar
        height.push_back(0);

        int sum = 0;
        int i = 0;
        while (i < (int)height.size())
        {
            if(s.empty() || height[i] > height[s.back()])
            {
                s.push_back(i++);
            }
            else
            {
                int t = s.back();
                s.pop_back();
                //这里还需要考虑stack为空的情况
                sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }

        return sum;
    }
};

