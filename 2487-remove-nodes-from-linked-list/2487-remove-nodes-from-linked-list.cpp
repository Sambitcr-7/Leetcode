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
    // Function to remove nodes from linked list
    ListNode* removeNodes(ListNode* head) {
        // If head is nullptr or only one node, return head
        if(head == nullptr || head->next == nullptr) return head;

        // Recursively call removeNodes for the next node
        ListNode* nextNode = removeNodes(head->next);

        // Check if the value of current node is less than next node
        if(head->val < nextNode->val) {
            // If yes, delete current node and return next node
            delete head;
            return nextNode;
        }

        // Otherwise, connect current node to next node and return current node
        head->next = nextNode;
        return head;
    }
};