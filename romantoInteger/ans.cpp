/**
 * @file ans.c
 * @brief
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * @version
 * @date 2015-05-07 15:15
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> dic;
        dic['M'] = 1000;
        dic['D'] = 500;
        dic['C'] = 100;
        dic['L'] = 50;
        dic['X'] = 10;
        dic['V'] = 5;
        dic['I'] = 1;

        int result = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (dic[s[i]] < dic[s[i + 1]])
                result -= dic[s[i]];
            else
                result += dic[s[i]];
        }

        result += dic[s[s.size() - 1]];

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.romanToInt("MMMCMXCIX") << endl;

    return 0;
}
