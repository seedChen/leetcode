/**
 * @file ans.cpp
 * @brief
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1,
 * otherwise return 0.
 *
 * You may assume that the version strings are non-empty
 * and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to
 * separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 * @version
 * @date 2015-08-20 10:04
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
private:
    int cmp(string& s1, string& s2)
    {
        int i = 0;
        while (i < s1.size() && s1[i] == '0') i++;
        s1 = s1.substr(i);

        i = 0;
        while (i < s2.size() && s2[i] == '0') i++;
        s2 = s2.substr(i);

        if (s1.size() > s2.size())
            return 1;
        else if (s1.size() < s2.size())
            return -1;
        else
        {
            if (s1 > s2)
                return 1;
            else if (s1 < s2)
                return -1;
            else
                return 0;
        }
    }

public:
    int compareVersion(string version1, string version2) {
        if (version1.size() == 0 || version2.size() == 0)
            return 0;
        vector<string> v1;
        vector<string> v2;
        stringstream ss1(version1);
        stringstream ss2(version2);

        string str;
        while (getline(ss1, str, '.'))
            v1.push_back(str);
        while (getline(ss2, str, '.'))
            v2.push_back(str);

        int i = 0;
        while (i < v1.size() && i < v2.size())
        {
            int ret = cmp(v1[i], v2[i]);
            if (ret != 0)
                return ret;
            else
                ++i;
        }

        if (v1.size() > v2.size())
        {
            for (; i < v1.size(); ++i)
            {
                int j = 0;
                while (j < v1[i].size() && v1[i][j] == '0') j++;
                if (j != v1[i].size())
                    return 1;
            }
            return 0;
        }
        else if (v1.size() < v2.size())
        {
            for (; i < v2.size(); ++i)
            {
                int j = 0;
                while (j < v2[i].size() && v2[i][j] == '0') j++;
                if (j != v2[i].size())
                    return -1;
            }
            return 0;
        }
        else
            return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.compareVersion("1.0", "1") << endl;

    return 0;
}

