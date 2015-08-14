/**
 * @file ans.cpp
 * @brief
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * @version
 * @date 2015-06-10 11:28
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    // we can use stringstream and getline() instead.
    void split(string& path, vector<string>& ret)
    {
        size_t pos1 = 0;
        size_t  pos2 = path.find('/');
        while (pos2 != string::npos)
        {
            ret.push_back(path.substr(pos1, pos2 - pos1));
            pos1 = pos2 + 1;
            pos2 = path.find('/', pos1);
        }
        ret.push_back(path.substr(pos1));
    }

public:
    string simplifyPath(string path)
    {
        string result;
        vector<string> splitRet;
        vector<string> stack;
        split(path, splitRet);

        for (int i = 0; i < (int)splitRet.size(); i++)
        {
            if (!splitRet[i].empty())
            {
                if (splitRet[i] == ".")
                {
                    continue;
                }
                else if (splitRet[i] == "..")
                {
                    if (!stack.empty())
                        stack.pop_back();
                }
                else
                {
                    stack.push_back(splitRet[i]);
                }
            }
        }

        for (int i = 0; i < (int)stack.size(); i++)
        {
            result = result + "/" + stack[i];
        }

        return stack.empty() ? "/" : result;
    }
};

