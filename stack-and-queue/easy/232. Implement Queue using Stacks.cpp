// https://leetcode.com/problems/implement-queue-using-stacks/



// 1. Enqueue costly -> O(n)
//    dequeue -> O(1)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty() == true)
            s1.push(x);
        else {
            while(s1.empty() == false) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(s2.empty() == false) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int e = s1.top();
        s1.pop();
        return e;
    }
    
    /** Get the front element. */
    int peek() {
        int e = s1.top();
        return e;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};



// 2. dequeue costly -> O(n)
//    enqueue -> O(1)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;

    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()) {
            while(s1.empty() == false) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};