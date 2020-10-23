// https://leetcode.com/problems/backspace-string-compare/

#include<bits/stdc++.h>
using namespace std;


// O(n) time & O(n) space -> using stack
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        for(char c: S) {
            if(c == '#') {
                if(s.empty() == false)
                    s.pop();
            } else {
                s.push(c);
            }
        }
        S = ""; 
        while(s.empty() == false) {
            S += s.top();
            s.pop();
        }
        
        for(char c: T) {
            if(c == '#') {
                if(s.empty() == false) 
                    s.pop();
            } else {
                s.push(c);
            }
        }
        T = "";
        while(s.empty() == false) {
            T += s.top();
            s.pop();
        }
        return S == T;
    }
};


// O(n) time & O(1) space -> two pointers
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int k = 0, p = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '#') {
                k--;
                k = max(0, k);
            } else {
                S[k] = S[i];
                k++;
            }
        }
        
        for(int i = 0; i < T.length(); i++) {
            if(T[i] == '#') {
                p--;
                p = max(0, p);
            } else {
                T[p] = T[i];
                p++;
            }
        }
        
        cout << k << endl << p << endl;
        
        cout << S << " " << T;
        
        if(k != p)
            return false;
        else {
            for(int i = 0; i < k; i++) {
                if(S[i] != T[i])
                    return false;
            }
        }
        
        return true;
    }
};
