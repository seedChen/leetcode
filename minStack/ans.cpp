/**
 * @file ans.cpp
 * @brief
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * • push(x) -- Push element x onto stack.
 * • pop() -- Removes the element on top of the stack.
 * • top() -- Get the top element.
 * • getMin() -- Retrieve the minimum element in the stack.
 *
 *
 * @version
 * @date 2015-08-13 22:28
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> s;
    vector<int> minStack;

public:
    void push(int x) {
            if (minStack.empty() || x <= minStack.back())
            {
                        minStack.push_back(x);
                    }
            s.push_back(x);
        }

    void pop() {
            if (s.back() == minStack.back())
                minStack.pop_back();

            s.pop_back();
        }

    int top() {
            return s.back();
        }

    int getMin() {
            return minStack.back();
        }
};

