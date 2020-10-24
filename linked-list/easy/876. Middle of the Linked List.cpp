// https://leetcode.com/problems/middle-of-the-linked-list/



// O(n^2) -> two passes of LL
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }
        if(count % 2 == 0) {
            count++;
        }
        for(int i = 0; i < count / 2; i++) {
            head = head -> next;
        }
        return head;
    }
};


// O(n) time -> 1 pass of LL
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *low, *high;
        low = high = head;
        while(high != NULL && high -> next != NULL) {
            high = high -> next -> next;
            low = low -> next;
        }
        return low;
    }
};