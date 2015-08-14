/**
 * @file ans.c
 * @brief
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 *
 * @version
 * @date 2015-05-15 16:26
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    if (NULL == head)
        return NULL;

    struct ListNode preHead;
    preHead.next = head;
    struct ListNode* pre = &preHead;
    struct ListNode* p1 = pre->next;
    struct ListNode* p2 = pre->next->next;

    while (pre && p1 && p2)
    {
        pre->next = p1->next;
        p1->next = p2->next;
        p2->next = p1;

        pre = p1;
        if (p1->next)
            p1 = p1->next;
        else
            break;
        if (p1->next)
            p2 = p1->next;
        else
            break;
    }

    return preHead.next;
}

