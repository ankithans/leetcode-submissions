// https://leetcode.com/problems/merge-two-sorted-lists/


// solution
// time O(m + n) & space O(1)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head, *tail;
        if(l1 -> val >= l2 -> val) {
            head = tail = l2;
            l2 = l2 -> next;
        } else {
            head = tail = l1;
            l1 = l1 -> next;
        }
        while(l1 && l2) {
            if(l1 -> val >= l2 -> val) {
                tail -> next = l2;
                tail = tail -> next;
                l2 = l2 -> next;
            } else {
                tail -> next = l1;
                tail = tail -> next;
                l1 = l1 -> next;
            }
        }
        if(l1) {
            tail -> next = l1;
        } else {
            tail -> next = l2;
        }
        return head;
    }
};