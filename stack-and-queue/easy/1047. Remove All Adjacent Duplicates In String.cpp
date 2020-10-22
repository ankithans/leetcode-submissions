// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/


// using stack
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        stack<char> st;
        for(int i = 0; i < S.length(); i++) {
            if(st.empty()) st.push(S[i]);
            else if(st.top() == S[i]) {
                st.pop();
            } else {
                st.push(S[i]);
            }
        }
        while(st.empty() == false) {
            res += st.top(); st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// using string as a stack
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for(int i = 0; i < S.length(); i++) {
            if(res.empty()) res.push_back(S[i]);
            else if(res.back() == S[i]) {
                res.pop_back();
            } else {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};