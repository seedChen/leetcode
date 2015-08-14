/**
 * @file ans.cpp
 * @brief
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * @version
 * @date 2015-05-15 14:57
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <set>
#include <vector>
#include <stddef.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
bool cmp(const ListNode* l, const ListNode* r)
{
    return l->val < r->val;
}

typedef bool (*cmpFunc)(const ListNode*, const ListNode*);
#endif

class cmp
{
    bool operator()(const ListNode* l, const ListNode* r)
    {
        return l->val < r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() <= 0)
            return NULL;

        multiset<ListNode*, cmp> minHeap;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* p = lists[i];
            if (p)
            {
                minHeap.insert(p);
            }
        }

        multiset<ListNode*, cmpFunc>::iterator it;

        ListNode resultPre(0);
        ListNode* nextNode = &resultPre;;

        while(!minHeap.empty())
        {
            it = minHeap.begin();
            nextNode->next = (*it);
            nextNode = nextNode->next;

            if ((*it)->next)
            {
                minHeap.insert((*it)->next);
            }
            minHeap.erase(it);
        }

        return resultPre.next;
    }
};

