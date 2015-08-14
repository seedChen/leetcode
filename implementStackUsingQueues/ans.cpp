/**
 * @file ans.cpp
 * @brief
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push
 * to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively.
 * You may simulate a queue by using a list or deque (double-ended queue),
 * as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 *
 * @version
 * @date 2015-08-14 14:40
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <queue>

using namespace std;

class Stack {
public:
    queue<int> q1_;
    queue<int> q2_;

public:
    // Push element x onto stack.
    void push(int x) {
        if (q1_.empty())
            q2_.push(x);
        else
            q1_.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (empty())
            return;

        if (q1_.empty())
        {
            while (q2_.size() != 1)
            {
                q1_.push(q2_.front());
                q2_.pop();
            }
            q2_.pop();
        }
        else
        {
            while (q1_.size() != 1)
            {
                q2_.push(q1_.front());
                q1_.pop();
            }
            q1_.pop();
        }
    }

    // Get the top element.
    int top() {
        if (q1_.empty())
            return q2_.back();
        else
            return q1_.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1_.empty() && q2_.empty();
    }
};

