// https://leetcode.com/problems/first-bad-version/


/*
    1  2  3  4  5  6
    [ G, G, B, B, B, B ]

    minimize the api calls isBadVersion(version)
    one bad version leads to subsequent bad versions

    simlilar to finding the pivot rotated array
    [ 4, 5, 6, 1, 2, 3 ]

*/

// naive solution -> linear search O(n)
class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0;
        for(i = 0; i < n; i++) {
            if(isBadVersion(i) == true)
                break;
        }
        return i;
}
};


// binary search -> O(logn)
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, result = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

