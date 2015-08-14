/**
 * @file ans.cpp
 * @brief
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 * @version
 * @date 2015-05-10 12:43
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string nextStr;
        string lastStr;

        if (n < 1)
            return lastStr;

        lastStr.push_back('1');
        if (n == 1)
            return lastStr;

        string* next = &nextStr;
        string* last = &lastStr;

        for (int i = 1; i < n; i++)
        {
            for(int j = 0; j < last->size(); j++)
            {
                int count = 1;
                while((*last)[j] == (*last)[j + 1] && j < last->size())
                {
                    j++;
                    count++;
                }
                next->append(to_string(count));
                next->push_back((*last)[j]);
            }

            string* tmp = last;
            last = next;
            next = tmp;

            next->clear();
        }

        return *last;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.countAndSay(4) << endl;

    return 0;
}

