/**
 * @file ans.cpp
 * @brief
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 * @version
 * @date 2015-06-19 09:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution
{
private:
    void helper(string s, int divisions, vector<string>& ret, vector<string>& ipSegments)
    {
        if (divisions == 1)
        {
            if (s.size() >= 2 && s[0] == '0')
                return;
            if (atoi(s.c_str()) <= 255)
            {
                string ip;
                for (int i = 0; i < (int)ipSegments.size(); i++)
                {
                    ip = ip + ipSegments[i] + '.';
                }
                ip += s;

                ret.push_back(ip);
            }
        }
        else
        {
            divisions--;

            if ((int)s.size() - 1 >= divisions)
            {
                ipSegments.push_back(s.substr(0, 1));
                helper(s.substr(1), divisions, ret, ipSegments);
                ipSegments.pop_back();
            }

            if (s[0] == '0')
                return;

            if ((int)s.size() - 2 >= divisions)
            {
                ipSegments.push_back(s.substr(0, 2));
                helper(s.substr(2), divisions, ret, ipSegments);
                ipSegments.pop_back();
            }

            if ((int)s.size() - 3 >= divisions)
            {
                string ipSegment = s.substr(0, 3);
                if (atoi(ipSegment.c_str()) <= 255)
                {
                    ipSegments.push_back(ipSegment);
                    helper(s.substr(3), divisions, ret, ipSegments);
                    ipSegments.pop_back();
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> ipSegments;

        if (s.size() < 4 || s.size() > 12)
            return result;
        helper(s, 4, result, ipSegments);

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> ret = s.restoreIpAddresses("010010");
    for (auto i : ret)
        cout << i << endl;

    return 0;
}
