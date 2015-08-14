/**
 * @file ans.cpp
 * @brief
 * Given an integer, write a function to determine if it is a power of two.
 *
 * @version
 * @date 2015-08-13 22:58
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return ((n - 1) & n) == 0;
    }
};

