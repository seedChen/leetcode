/**
 * @file ans.cpp
 * @brief
 * Given a non-negative integer num, repeatedly add all its digits until
 * the result has only one digit.
 *
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2.
 * Since 2 has only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 *
 * @version
 * @date 2015-08-17 15:48
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;

        int ret = num % 9;
        if (ret == 0)
            return 9;
        else
            return ret;
    }
};

