// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


// Naive Solution -> O(n^2logn^2)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};


// Binary Search
