// https://leetcode.com/problems/implement-stack-using-queues/

#include<bits/stdc++.h>
using namespace std;

// 1. making push costly
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(q1.empty() == false) {
            q2.push(q1.front());
            q1.pop();
        }
        // swap names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()) 
            return -1;
        int e = q1.front();
        q1.pop();
        return e;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) 
            return -1;
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};


// 2. making pop costly
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
       q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()) 
            return -1;
        
        // leave 1 element in q1 and push others to q2
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int e = q1.front();
        q1.pop();
        
        // swap the names of queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        
        return e;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) 
            return -1;
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
        
        // swap the name
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
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