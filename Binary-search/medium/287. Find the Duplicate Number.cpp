// https://leetcode.com/problems/find-the-duplicate-number/


// Naive solution -> O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }

};


// hashing
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++) {
            if(us.find(nums[i]) != us.end()) {
                return nums[i];
            } else {
                us.insert(nums[i]);
            }
        }
        return -1;
    }

};


// Linked List Cycle detection method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};