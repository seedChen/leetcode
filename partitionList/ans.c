/**
 * @file ans.c
 * @brief
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 * @version
 * @date 2015-06-16 11:48
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

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode firstHalfHead = {0, NULL};
    struct ListNode* firstHalfTail = &firstHalfHead;

    struct ListNode lastHalfHead = {0, NULL};
    struct ListNode* lastHalfTail = &lastHalfHead;

    struct ListNode tmpHead = {0, head};
    struct ListNode* cur = head;
    struct ListNode* pre = &tmpHead;

    while (cur)
    {
        if (cur->val < x)
        {
            firstHalfTail->next = cur;
            firstHalfTail = firstHalfTail->next;
        }
        else
        {
            lastHalfTail->next = cur;
            lastHalfTail = lastHalfTail->next;
        }

        pre->next = cur->next;
        cur->next = NULL;
        cur = pre->next;
    }

    firstHalfTail->next = lastHalfHead.next;

    return firstHalfHead.next;
}

int main(int argc, char *argv[])
{
    struct ListNode n6 = {2, NULL};
    struct ListNode n5 = {5, &n6};
    struct ListNode n4 = {2, &n5};
    struct ListNode n3 = {3, &n4};
    struct ListNode n2 = {4, &n3};
    struct ListNode n1 = {1, &n2};

    struct ListNode* p = partition(&n1, 3);

    while (p)
    {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}

