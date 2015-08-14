/**
 * @file ans.cpp
 * @brief
 * Given an array of words and a length L, format the text such that each line
 * has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 *
 * @version
 * @date 2015-06-10 08:54
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> result;
        string line;
        vector<string> lineWords;

        if (maxWidth == 0)
        {
            result.push_back("");
            return result;
        }

        for (int i = 0; i < (int)words.size(); i++)
        {
            if ((int)(words[i].size() + line.size()) < maxWidth)
            {
                line = line + words[i] + " ";
                lineWords.push_back(words[i]);
                continue;
            }
            else if ((int)(words[i].size() + line.size()) == maxWidth)
            {
                line += words[i];
                result.push_back(line);
                line.clear();
                lineWords.clear();
            }
            else
            {
                int l = 0;
                for (int j = 0; j < (int)lineWords.size(); j++)
                    l += lineWords[j].size();

                int left = maxWidth - l;
                int slotSize = 0;
                int more = 0;
                if (lineWords.size() > 1)
                {
                    slotSize = left / (lineWords.size() - 1);
                    more = left % (lineWords.size() - 1);

                    line.clear();
                    line = lineWords[0];
                    string slotSizeSpace = string(slotSize, ' ');
                    for (int j = 1; j < (int)lineWords.size(); j++)
                    {
                        if (more)
                        {
                            line = line + " " + slotSizeSpace + lineWords[j];
                            more--;
                        }
                        else
                            line = line + slotSizeSpace + lineWords[j];
                    }
                }
                else
                {
                    slotSize = left;
                    string slotSizeSpace = string(slotSize, ' ');
                    line = lineWords[0] + slotSizeSpace;
                }


                result.push_back(line);
                line.clear();
                lineWords.clear();
                i--;
            }
        }

        if (lineWords.size())
        {
            int left = maxWidth - line.size();
            string leftSpace = string(left, ' ');
            line += leftSpace;
            result.push_back(line);
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    string s[] = {"Listen","to","many,","speak","to","a","few."};
    vector<string> t(s, s + 6);
    Solution so;
    vector<string> ret = so.fullJustify(t, 6);
    for (auto v : ret)
    {
        cout << v << endl;
    }
    return 0;
}
