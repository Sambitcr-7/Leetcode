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
        ListNode* dummy = new ListNode(0); // Create a dummy node
        dummy->next = head; // Point dummy node to head

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (first == nullptr)
                return nullptr; // Error handling if n is greater than the length of the list
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        second->next = second->next->next;

        return dummy->next; // Return the updated head
    }
};