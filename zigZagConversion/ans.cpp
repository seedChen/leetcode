/**
 * @file ans.cpp
 * @brief
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".)
 *
 * @version
 * @date 2015-04-17 20:29
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int nRows)
    {
        if (s.size() == 0 || nRows <= 1)
            return s;

        string result;
        for (size_t i = 0; i < s.size(); i = i + 2 * (nRows - 1))
            result.push_back(s[i]);

        for (int i = 1; i < nRows - 1; ++i)
        {
            result.push_back(s[i]);
            for (size_t j = 2 * (nRows - 1); j < s.size(); j = j + 2 * (nRows - 1))
            {
                result.push_back(s[j - i]);
                result.push_back(s[j + i]);
            }
        }

        for (size_t i = nRows - 1; i < s.size(); i = i + 2 * (nRows - 1))
            result.push_back(s[i]);

        return result;
    }
};

int main(int argc, char *argv[])
{
    std::string str = "PAYPALISHIRING";
    int nRows = 3;
    Solution s;
    cout << s.convert(str, nRows) << endl;;
    return 0;
}

