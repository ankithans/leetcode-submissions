// https://leetcode.com/problems/guess-number-higher-or-lower/

// Naive sol -> apply linear search instead of binary search


// efficient solution
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n; 
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);
            if(res == 0)
                return mid;
            else if(res == -1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};