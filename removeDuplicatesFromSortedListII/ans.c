/**
 * @file ans.c
 * @brief
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 * @version
 * @date 2015-06-14 19:40
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (NULL == head)
        return NULL;
    if (head->next == NULL)
        return head;

    struct ListNode* pre = head;
    struct ListNode* cur = head->next;

    struct ListNode newHead;
    newHead.next = NULL;
    struct ListNode* newTail = &newHead;

    // For easy to understand, deal the first node later.
    int flag = 0;
    if (head->val != head->next->val)
        flag = 1;

    while (cur)
    {
        if (pre->val != cur->val && (cur->next == NULL || cur->val != cur->next->val))
        {
            newTail->next = cur;
            cur = cur->next;
            pre->next = cur;
            newTail = newTail->next;
            newTail->next = NULL;
        }
        else
        {
            pre = pre->next;
            cur = cur->next;
        }
    }

    if (flag)
    {
        struct ListNode* p = head;
        head = head->next;
        p->next = newHead.next;
        newHead.next = p;
    }

    return newHead.next;
}

int main(int argc, char *argv[])
{
    struct ListNode h1;
    struct ListNode h2;
    struct ListNode h3;
    h1.val = 1;
    h1.next = &h2;
    h2.val = 2;
    h2.next = &h3;
    h3.val = 2;
    h3.next = NULL;
    deleteDuplicates(&h1);
    return 0;
}

