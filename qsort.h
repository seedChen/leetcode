/**
 * @file qsort.h
 * @brief
 * a quick sort code
 *
 * @version
 * @date 2015-04-13 09:18
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#ifndef _QA_QSORT_H_
#define _QA_QSORT_H_

#include <vector>
#include <stdexcept>

using namespace std;

void qsort(vector<int> &numbers, int l, int r)
{
    if (l < 0 || r > (int)numbers.size())
        throw out_of_range("Invalid parameters");

    if (l < r)
    {
        int i = l, j = r, x = numbers[l];
        while (i < j)
        {
            while(i < j && numbers[j] >= x)
                j--;
            if(i < j)
                numbers[i++] = numbers[j];

            while(i < j && numbers[i] < x)
                i++;
            if(i < j)
                numbers[j--] = numbers[i];
        }
        numbers[i] = x;
        qsort(numbers, l, i - 1);
        qsort(numbers, i + 1, r);
    }
}

#endif // _QA_QSORT_H_

