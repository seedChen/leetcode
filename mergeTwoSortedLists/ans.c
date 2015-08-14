/**
 * @file ans.c
 * @brief
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * @version
 * @date 2015-05-14 16:46
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (NULL == l1)
        return l2;
    if (NULL == l2)
        return l1;

    struct ListNode resultPre;
    struct ListNode* p = &resultPre;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1 == NULL)
        p->next = l2;
    else if (l2 == NULL)
        p->next = l1;

    return resultPre.next;
}

