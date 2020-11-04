// https://leetcode.com/problems/odd-even-linked-list/


// inplace -> two pass
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *curr = head;
        ListNode *end = head;
        int c = 0;
        if(!head)
            return head;
        while(end -> next) {
            end = end -> next;
            c++;
        }
        c = c&1?(c/2)+1:c/2;
        
        while(c--) {
            end -> next = curr -> next;
            curr -> next = curr -> next -> next;
            end -> next -> next = NULL;
            
            curr = curr -> next;
            end = end -> next;
        }
        return head;
    }
};


// inplace -> one pass
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *odd = head, *even = head -> next, *evenHead = head -> next;
        while(even && even -> next) {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = evenHead;
        return head;
    }
};