/**
 * @file ans.c
 * @brief
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * @version
 * @date 2015-06-14 19:03
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (NULL == head)
        return NULL;

    struct ListNode* p = head;
    while (p->next)
    {
        if (p->val == p->next->val)
        {
            struct ListNode* q = p->next;
            p->next = q->next;
            free(q);
            continue;
        }
        p = p->next;
    }

    return head;
}

