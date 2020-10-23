// https://leetcode.com/problems/make-the-string-great/

#include<bits/stdc++.h>
using namespace std;

// using stacks -> O(n) time & O(n) space
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            while(!st.empty() && ((st.top() == s[i + 1] + 32) || (st.top() == s[i + 1] - 32))) {
                st.pop();
                i++;
            }
        }
        
        s = "";
        while(st.empty() == false) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


