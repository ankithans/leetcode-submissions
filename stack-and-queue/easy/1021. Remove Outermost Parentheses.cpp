// https://leetcode.com/problems/remove-outermost-parentheses/

// wow solution
// O(n)
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(' && opened++ > 0) res += S[i];
            if(S[i] == ')' && opened-- > 1) res += S[i];
        }
        return res;
    }
};


// Stack solution
// time -> O(n) 
// space -> O(n) 
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        stack<char> st;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(') {
                if(st.size() > 0) {
                    res += S[i];
                }
                st.push(S[i]);
            } else {
                if(st.size() > 1) {
                    res += S[i];
                }
                st.pop();
            }
        }
        return res;
    }
};