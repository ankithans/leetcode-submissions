// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
    Steps:
    	1. find the smallest element
        2. then choose the side where target should be!
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        int left = 0, right = nums.size() - 1;
        
        // for finding the smallest element
        while(left < right) {
            int midpoint = left + (right - left) / 2;
            if(nums[midpoint] > nums[right])
                left = midpoint + 1;
            else
                right = midpoint;
        }
        
        int start = left;
        left = 0, right = nums.size() - 1;
        
        // select the half
        if(target >= nums[start] && target <= nums[right])
            left = start;
        else
            right = start;

        // normal binary search
        while(left <= right) {
            int midpoint = left + (right - left) / 2;
            if(nums[midpoint] == target){
                return midpoint;
            } else if(nums[midpoint] < target) {
                left = midpoint + 1;
            } else {
                right = midpoint - 1;
            }
        }
        return -1;
    }
};