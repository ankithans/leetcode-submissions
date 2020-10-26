// https://leetcode.com/problems/next-greater-node-in-linked-list/


// Naive Solution -> O(n^2)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *curr = head;
        vector<int> v;
        while(curr && curr -> next) {
            ListNode *temp = curr -> next;
            while(temp) {
                if(curr -> val < temp -> val) {
                    v.push_back(temp -> val);
                    break;
                } else {
                    if(temp -> next == NULL)
                        v.push_back(0);
                    temp = temp -> next;
                }
            }
            curr = curr -> next;
        }
        v.push_back(0);
        return v;
    }
};