// https://leetcode.com/problems/sqrtx/

// concept	    mid*mid  <  x
// optimized	mid < x / mid


// O(n)
class Solution {
public:
    long long int mySqrt(int x) {
        long long int i = 1;
        while(i*i <= x) {
            i++;
        }
        
        return i - 1;
    }
};


// O(logn)
class Solution {
public:
    int mySqrt(int x) {
        int ans = -1;
        if(x == 0 || x == 1) 
            return x;
        int l = 1, r = x / 2;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mid == x / mid) return mid;
            else if(mid < x / mid) { l = mid + 1; ans = mid; }
            else r = mid - 1;
        }
        return ans;
    }
};