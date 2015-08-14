/**
 * @file addTwoNumbers.cpp
 * @brief
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a
 * single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * @version
 * @date 2015-04-13 10:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *retList = NULL;
        ListNode *pTail = retList;
        int carry = 0;
        int addend1 = 0, addend2 = 0, val = 0;
        int sum = 0;

        while (p1 != NULL || p2 != NULL || carry != 0)
        {
            addend1 = (NULL == p1 ? 0 : p1->val);
            addend2 = (NULL == p2 ? 0 : p2->val);
            sum = addend1 + addend2 + carry;
            carry = sum / 10;
            val = sum % 10;

            ListNode *node = new ListNode(val);
            if (pTail)
            {
                pTail->next = node;
                pTail = node;
            }
            else
            {
                retList = node;
                pTail = node;
            }

            if (p1)
                p1 = p1->next ;
            if (p2)
                p2 = p2->next;
        }

        return retList;
    }
};

int main(int argc, char *argv[])
{
    ListNode n1(2);
    ListNode n2(4);
    ListNode n3(3);
    n2.next = &n3;
    n1.next = &n2;

    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(4);
    ListNode n8(4);
    n7.next = &n8;
    n6.next = &n7;
    n5.next = &n6;

    Solution s;
    ListNode *ret = s.addTwoNumbers(&n1, &n5);

    for (; ret != NULL; ret = ret->next)
        cout << ret->val << endl;

    return 0;
}
