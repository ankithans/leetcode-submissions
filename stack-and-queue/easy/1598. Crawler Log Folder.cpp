// https://leetcode.com/problems/crawler-log-folder/

#include<bits/stdc++.h>
using namespace std;


// stack solution -> O(n) time & space
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string s: logs) {
            if(s == "../") {
                if(st.empty() == false)
                    st.pop();
            } else if(s == "./") {
                continue;
            } else {
                st.push(s);
            }
        }
        return st.size() == 0 ? 0 : st.size();
    }
};



// without stacks -> O(n) time & O(1) space
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(string s: logs) {
            if(s == "../") {
                res--;
                res = max(0, res);
            } else if(s == "./") {
                continue;
            } else {
                res++;
            }
        }
        return res;
    }
};