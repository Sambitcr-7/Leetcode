class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        int sum = 0;
        head = head->next;
        ListNode* ans = new ListNode(sum);
        ListNode* tail = ans;
        while(head)
        {
            sum += head->val;
            if(not head->val)
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            }
            head = head->next;
        }
        return ans->next;
    }
};