// https://leetcode.com/problems/palindrome-linked-list/


// with stack O(n) space
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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        while(curr) {
            st.push(curr);
            curr = curr -> next;
        }
        curr = head;
        while(curr) {
            if(curr -> val != st.top() -> val)
                return false;
            st.pop();
            curr = curr -> next;
        }
        return true;
    }
};


// O(1) time
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast) slow = slow -> next;
        
        ListNode *prev = NULL, *curr = slow;
        while(curr) {
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        while(prev) {
            if(prev -> val != head -> val)
                return false;
            prev = prev -> next;
            head = head -> next;
        }
        return true;
    }
};