// https://leetcode.com/problems/is-subsequence/


// two pointer solution -> O(n), where n is the size of t
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;
        while(p1 < s.size() && p2 < t.size()) {
            if(s[p1] == t[p2])
                p1++;
            p2++;
        }
        return p1 == s.size();
    }
};

// recursive solution
class Solution {
public:
    bool isSubSeq(string str1, string str2, int m, int n) {
        if(m == 0) return true;
        if(n == 0) return false;
        
        if(str1[m - 1] == str2[n - 1])
            return isSubSeq(str1, str2, m - 1, n - 1);
        else 
            return isSubSeq(str1, str2, m, n - 1);
    }
    
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return isSubSeq(s, t, m, n);
    }
};