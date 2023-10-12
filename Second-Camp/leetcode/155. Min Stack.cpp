#include <bits/stdc++.h>
using namespace std;

class MinStack {
    vector<int>stack, minStack;
    int size;
public:
    MinStack() : size(0) {}
    
    void push(int val) {
        stack.push_back(val);
        if (size == 0 || minStack.back() >= val)
            minStack.push_back(val);
        size++;
    }
    
    void pop() {
        int val = stack.back();
        stack.pop_back();
        if (minStack.back() == val) minStack.pop_back();
        size--;
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */