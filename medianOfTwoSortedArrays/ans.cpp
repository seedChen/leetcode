/**
 * @file ans.cpp
 * @brief
 * There are two sorted arrays A and B of size m and n respectively. Find the
 * median of the two sorted arrays. The overall run time complexity should be
 * O(log (m+n)).
 *
 * @version
 * @date 2015-04-15 08:56
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Solution
{
private:
    double findKthSortedArrays(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (1 == k)
            return min(A[0], B[0]);

        int pa = min(k/2, m);
        int pb = k - pa;

        if (A[pa - 1] > B[pb - 1])
            return findKthSortedArrays(A, m, B+pb, n-pb, k-pb);
        else if (A[pa - 1] < B[pb - 1])
            return findKthSortedArrays(A+pa, m-pa, B, n, k-pa);
        else
            return A[pa - 1];
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if (m < 0 || n < 0)
            throw out_of_range("Invalid parameters");

        int total = m + n;
        if (total & 0x1)
            return findKthSortedArrays(A, m, B, n, total/2+1);
        else
            return (findKthSortedArrays(A, m, B, n, total/2+1)
                    + findKthSortedArrays(A, m, B, n, total/2)) / 2;
    }
};

int main(int argc, char *argv[])
{
    // int A[] = {1, 4, 5, 6};
    // int B[] = {2, 3, 4, 5};
    int A[] = {100000};
    int B[] = {100001};
    Solution s;

    cout << "the median is " << s.findMedianSortedArrays(A, sizeof(A), B, sizeof(B)) << endl;;

    return 0;
}

