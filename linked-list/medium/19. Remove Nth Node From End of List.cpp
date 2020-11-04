// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


// two pass solution
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode *curr = head;
        int count = 0;
        while(curr) {
            count++;
            curr = curr -> next;
        }
        int pos = count - n;
        
        if(pos == 0)
            return head -> next;
        curr = head;
        while(--pos) {
            curr = curr -> next;
        }
        ListNode *temp = curr -> next;
        curr -> next = curr -> next -> next;
        delete temp;
        return head;
    }
};


// two pointes approach
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n--)
            fast = fast -> next;
        if(fast == NULL)
            return head -> next;
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};