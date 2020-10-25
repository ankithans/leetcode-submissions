// https://leetcode.com/problems/intersection-of-two-linked-lists/



// hashing -> O(n) space and O(n + m) time
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA) {
            s.insert(headA);
            headA = headA -> next;
        }
        while(headB) {
            if(s.find(headB) != s.end())
                return headB;
            else
                headB = headB -> next;
        }
        return NULL;
    }
};



// O(n + m) time & O(1) space
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = 0, c2 = 0;
        ListNode *currA = headA, *currB = headB;
        while(currA) {
            c1++;
            currA = currA -> next;
        }
        while(currB) {
            c2++;
            currB = currB -> next;
        }
        currA = headA, currB = headB;
        if(c1 > c2) {
            for(int i = 0; i < c1 - c2; i++)
                currA = currA -> next;
        } else {
            for(int i = 0; i < c2 - c1; i++)
                currB = currB -> next;
        }
        while(currA != currB) {
            currA = currA -> next;
            currB = currB -> next;
        }
        return currA;
    }
};