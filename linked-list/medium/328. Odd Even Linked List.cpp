// https://leetcode.com/problems/odd-even-linked-list/


// not inplace -> two pass
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
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
            return head;
        ListNode *temp = head, *end = head;
        int c = 0;
        while(end -> next) {
            end = end -> next;
            c++;
        }
        
        if(c % 2 == 0)
            c = c/2 + 1;
        else
            c = c/2;
        
        while(c--) {
            end -> next = temp -> next;
            temp -> next = temp -> next -> next;
            end -> next -> next = NULL;
            
            temp = temp -> next;
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