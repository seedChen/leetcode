/**
 * @file ans.c
 * @brief
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 * @version
 * @date 2015-08-12 17:18
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    if (NULL == head || NULL == head->next)
        return head;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = head->next;

    while (curr)
    {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr)
                next = curr->next;
        }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    int len = 0;
    struct ListNode* p = head;
    while (p)
    {
            len++;
            p = p->next;
        }

    p = head;
    for (int i = 0; i < len / 2; i++)
    {
            p = p->next;
        }

    struct ListNode* q = reverseList(p);
    p = head;

    for (int i = 0; i < len / 2; i++)
    {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }

    return true;
}

