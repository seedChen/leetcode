/**
 * @file testQsort.cpp
 * @brief
 * test the qsort function
 *
 * @version
 * @date 2015-04-13 10:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include "../qsort.h"
#include <iostream>

int main(int argc, char *argv[])
{
    int origin[] = {8, 123, 5, 23, 0, -1, 27, 4, 4};
    vector<int> numbers(origin, origin + 9);
    qsort(numbers, 0, numbers.size() - 1);

    for (int i = 0; i < (int)numbers.size(); ++i)
        cout << numbers[i] << endl;

    return 0;
}
