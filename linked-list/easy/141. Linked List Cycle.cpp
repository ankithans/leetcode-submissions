// https://leetcode.com/problems/linked-list-cycle/


// hashing -> O(n) time & O(n) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> us;
        while(head != NULL) {
            if(us.find(head) != us.end()) {
                return true;
            } else {
                us.insert(head);
            }
            head = head -> next;
        }
        return false;
    }
};


// two pointer approach (tortoise-rare method) -> O(n) time & O(1) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next; 
            if(slow == fast)
                return true;
        }
        return false;
    }
};