// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

/*
    sorted in decreasing order
	1. both row and column wise

    return number of -ve numbers in a grid


    Here's the idea:
    [4,  3,  2,  ?] -> Found 3 negative numbers in this row
    [3,  ?,  ?,  ?] -> Found 1 negative number in this row
    [?,  ?, -1, -2] -> Found 2 negative numbers in this row 

*/

// O(n*m)    Naive
class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int count = 0;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                if(v[i][j] < 0)
                    count++;
            }
        }
        return count;
    }
};



// optimal -> O(n + m)
// it's done using linear search
int countNegatives(vector<vector<int>>& v) {
    int count = 0;
    int i = v.size() - 1;
    int j = 0;
    
    while(i >= 0 && j < v[i].size()) {
        if(v[i][j] < 0) {
            count += v[i].size() - j;
            i--;                
        } else
            j++;
    }
    return count;
}


// optimal -> binary search
// failed
class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
    int count = 0;
    int i = 0;

    while (i < v.size()) {
        int l = 0, r = v[i].size() - 1;
        int negativeStart = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(v[i][mid] < 0) {
                negativeStart = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(negativeStart != -1)
            count += v.size() - negativeStart;
        i++;
    }
    return count;    
}
};

