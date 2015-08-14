/**
 * @file ans.c
 * @brief
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * @version
 * @date 2015-05-15 21:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if (NULL == head)
        return NULL;
    if (k < 0)
        return NULL;

    int len = 0;
    struct ListNode* p = head;
    while (p)
    {
        len++;
        p = p->next;
    }

    if (len < k)
        return head;

    struct ListNode result;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    struct ListNode* lastTail = &result;
    int i, j;
    for (i = 0; i < len / k; i++ )
    {
        struct ListNode* first = curr;
        for (j = 0; j < k; j++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        lastTail->next = prev;
        lastTail = first;
        prev = NULL;
    }

    lastTail->next = curr;

    return result.next;
}

int main(int argc, char *argv[])
{
    struct ListNode node;
    node.val = 1;
    node.next = NULL;

    struct ListNode* p = reverseKGroup(&node, 1);
    while (p)
    {
        printf("%d", p->val);
        p = p->next;
    }

    return 0;
}

