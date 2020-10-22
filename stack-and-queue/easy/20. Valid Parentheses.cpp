// https://leetcode.com/problems/valid-parentheses/


// using stack
class Solution {
public:
    bool match(char a, char b) {
        return ((a == '(' && b == ')') ||
                (a == '{' && b == '}') || 
                (a == '[' && b == ']'));
    }
    
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty())
                    return false;
                else if(match(st.top(), s[i])) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty() == true;
    }
};