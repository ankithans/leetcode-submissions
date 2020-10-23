// https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>
using namespace std;

// O(1) time & O(n) space
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1, s2;
    
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() == false) {
            if(x > s2.top()) {
                s2.push(s2.top());
            } else {
                s2.push(x);
            }
        } else {
            s2.push(x);
        }
    }
    
    void pop() {
        if(s2.empty() == false && s2.empty() == false) {
            s1.pop();
            s2.pop();
        }
        
    }
    
    int top() {
        if(s1.empty() == false)
            return s1.top();
        else 
            return -1;
    }
    
    int getMin() {
        if(s2.empty() == false)
            return s2.top();
        else 
            return -1;
    }
};



// O(1) time and space
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long minEle;

    MinStack() {

    }
    
    void push(int x) {
        if(s.empty()) {
            minEle = x;
            s.push(x);
        }
        else if(x >= minEle) {
            s.push(x);
        } else {
            long x1, x2 = x;
            x1 = 2*x2 - minEle;
            s.push(x1);
            minEle = x2;
        }
    }
    
    void pop() {
        if(s.empty())
            return ;
        else if(s.top() >= minEle) {
            s.pop();
        } else {
            minEle = 2*minEle - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        else if(s.top() < minEle)
            return minEle;
        else
            return s.top();
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return minEle;
    }
};
