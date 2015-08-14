/**
 * @file ans.c
 * @brief
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * @version
 * @date 2015-05-12 15:16
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
        return NULL;

    struct ListNode* curr = head;
    while (curr != NULL)
    {
        if (curr->val == val)
        {
            if (curr->next != NULL)
            {
                struct ListNode *p =curr->next;
                curr->val = p->val;
                curr->next = p->next;
                free(p);
                continue;
            }
            else
            {
                struct ListNode *p = head;
                while (p != curr && p->next != curr)
                    p = p->next;

                if (p == curr)
                {
                    free(curr);
                    head =  NULL;
                }
                else if (p->next == curr)
                {
                    free(curr);
                    p->next = NULL;
                }
                return head;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main(int argc, char *argv[])
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = 1;
    p->next = NULL;

    removeElements(p, 1);
    return 0;
}
