/**
 * @file ans.c
 * @brief
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 *
 * @version
 * @date 2015-06-18 15:47
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

#if 0
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}
#endif

struct ListNode* recursivelyReverse(struct ListNode* curr, struct ListNode* next)
{
    if (next == NULL)
        return curr;
    else
    {
        struct ListNode* tmp = next->next;
        next->next = curr;
        return recursivelyReverse(next, tmp);
    }
}

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    return recursivelyReverse(NULL, head);
}

