/**
 * @file ans.c
 * @brief
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 * @version
 * @date 2015-06-03 16:54
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL)
        return NULL;

    struct ListNode* p = head;
    int n = 0;
    while(p->next)
    {
        p = p->next;
        n++;
    }

    n++;
    k = k % n;
    p->next = head;

    struct ListNode *q = head;
    for(int i = 0; i < n - k - 1; i++)
        q = q->next;

    head = q->next;
    q->next = NULL;

    return head;
}

