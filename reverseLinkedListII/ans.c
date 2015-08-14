/**
 * @file ans.c
 * @brief
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 *
 * @version
 * @date 2015-06-18 20:04
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

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode header = {0, head};
    struct ListNode* curr = &header;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    struct ListNode* prevTail = NULL;

    for (int i = 0; i < m - 1; i++)
        curr = curr->next;
    prevTail = curr;
    curr = curr->next;

    for (int i = 0; i < n - m + 1; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    prevTail->next->next = curr;
    prevTail->next = prev;

    return header.next;
}

int main(int argc, char *argv[])
{
    struct ListNode n2 = {5, NULL};
    struct ListNode n1 = {3, &n2};

    struct ListNode* p = reverseBetween(&n1, 1, 2);

    while (p)
    {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}

