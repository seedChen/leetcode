/**
 * @file ans.cpp
 * @brief
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing all ones and return its area.
 *
 * @version
 * @date 2015-06-16 10:55
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
private:
    int maxArea(vector<int>& height)
    {
        int i = 0;
        int maxArea = 0;

        height.push_back(0);
        vector<int> s;

        while (i < (int)height.size())
        {
            if (s.empty() || height[s.back()] < height[i])
            {
                s.push_back(i++);
            }
            else
            {
                int t = s.back();
                s.pop_back();

                maxArea = max(maxArea, height[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char> >& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int result = 0;

        for (int i = 0; i < row; i++)
        {
            vector<int> height(col, 0);
            for (int j = 0; j < col; j++)
            {
                for (int k = i; k >= 0; k--)
                {
                    if (matrix[k][j] == '0')
                        break;
                    else
                        height[j]++;
                }
            }

            result = max(result, maxArea(height));
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    char a[] = "1101";
    char b[] = "1101";
    char c[] = "1111";
    vector<char> va(a, a + 4);
    vector<char> vb(b, b + 4);
    vector<char> vc(c, c + 4);
    vector<vector<char> > matrix;
    matrix.push_back(va);
    matrix.push_back(vb);
    matrix.push_back(vc);
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
