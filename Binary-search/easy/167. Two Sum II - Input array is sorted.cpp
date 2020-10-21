// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


// Naive O(n^2)
/*
    1. use two loops
    2. for every element calculate the sum and compare
*/


// using hashing O(n)
// but it returns actual numbers not the indices!
class Solution {
public: 
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_set<int> s;
        for(int i = 0; i < numbers.size(); i++) {
            int temp = target - numbers[i];

            if(s.find(temp) != s.end())
                return {numbers[i], temp};
            s.insert(numbers[i]);
        }   
        return {};
    }
}; 


// Efficient O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            } else if(numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};