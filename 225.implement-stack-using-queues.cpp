/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    stack<int> stk;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stk.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int k =stk.top();
        stk.pop();
        return k;
    }
    
    /** Get the top element. */
    int top() {
        return stk.top();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

