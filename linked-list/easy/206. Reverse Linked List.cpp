// https://leetcode.com/problems/reverse-linked-list/


// iterative -> O(n) time & O(1) space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr != NULL) {
            ListNode *nextTemp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


// visualize to understand // https://www.youtube.com/watch?v=MRe3UsRadKw
// recursive -> O(n) time & O(n) space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        if(curr == NULL || curr -> next == NULL) 
            return curr;
        ListNode *p = reverseList(curr -> next);
        curr -> next -> next = curr;
        curr -> next = NULL;
        return p;
    }
};