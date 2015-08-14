/**
 * @file ans.c
 * @brief
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 *
 * @version
 * @date 2015-08-12 15:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
    if (NULL == node)
        return;

    struct ListNode* p = node->next;
    node->val = p->val;
    node->next = p->next;

    free(p);
}

