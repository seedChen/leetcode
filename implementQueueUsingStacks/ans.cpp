/**
 * @file ans.cpp
 * @brief
 * Implement the following operations of a queue using stacks.
 * • push(x) -- Push element x to the back of queue.
 * • pop() -- Removes the element from in front of queue.
 * • peek() -- Get the front element.
 * • empty() -- Return whether the queue is empty.
 * Notes:
 * •You must use only standard operations of a stack -- which means only push
 * to top, peek/pop from top, size, and is empty operations are valid.
 * •Depending on your language, stack may not be supported natively.
 * You may simulate a stack by using a list or deque (double-ended queue),
 * as long as you use only standard operations of a stack.
 * •You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 * @version
 * @date 2015-08-13 22:49
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s1;
    stack<int> s2;

    void pourS1ToS2()
    {
        while (!s1.empty())
        {
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
    }

public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s2.empty())
            pourS1ToS2();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (s2.empty())
            pourS1ToS2();
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};

