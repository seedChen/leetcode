/**
 * @file ans.c
 * @brief
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.)
 *
 * @version
 * @date 2015-08-15 15:01
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getListSize(struct ListNode *head)
{
    if (head == NULL)
        return 0;

    int size = 0;
    while (head)
    {
            size++;
            head = head->next;
        }

    return size;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    int sizeA = getListSize(headA);
    int sizeB = getListSize(headB);

    int n = 0;
    struct ListNode* p = NULL;
    struct ListNode* q = NULL;

    if (sizeA < sizeB)
    {
            n = sizeB - sizeA;
            p = headB;
            q = headA;
        }
    else
    {
            n = sizeA - sizeB;
            p = headA;
            q = headB;
        }

    while (n)
    {
            n--;
            p = p->next;
        }

    while (p)
    {
            if (p == q)
                return p;
            p = p->next;
            q = q->next;
        }

    return NULL;
}

