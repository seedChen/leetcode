/**
 * @file ans.c
 * @brief
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list
 *    becomes 1->2->3->5.
 *
 *    Note:
 *    Given n will always be valid.
 *    Try to do this in one pass.
 *
 *
 * @version
 * @date 2015-05-14 11:36
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (!head)
        return head;

    struct ListNode* p = head;
    struct ListNode* q = head;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    for (; n > 0; n--)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        q = q->next;
        free(head);
        return q;
    }

    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    struct ListNode* tmp = q->next;
    q->next = tmp->next;
    free(tmp);

    return head;
}
