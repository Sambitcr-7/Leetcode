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
    ListNode* middleNode(ListNode* head) {
          // Initialize two pointers, fast and slow, both pointing to the head
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer two steps at a time and slow pointer one step at a time
        // When fast reaches the end of the list (nullptr), slow will be at the middle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;      // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps
        }
        
        // At this point, slow is at the middle of the list
        return slow;
    }
};