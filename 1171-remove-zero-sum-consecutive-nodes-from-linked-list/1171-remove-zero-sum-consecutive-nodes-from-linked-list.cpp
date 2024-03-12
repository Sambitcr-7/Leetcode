class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixsum = 0;
        unordered_map<int, ListNode*> mp;
        ListNode *dummynode = new ListNode (0);
        dummynode->next = head;  // Connect the dummy node to the head of the list.
        mp[prefixsum] = dummynode;
        
        while(head!=NULL){
            prefixsum += head->val;
            if(mp.find(prefixsum)!=mp.end()){
                ListNode *start = mp[prefixsum]->next;
                ListNode *temp = start;
                int psum = prefixsum;
                
                // Remove nodes with sum equals to psum
                while(temp!=head){
                    psum += temp->val;
                    if(temp!=head){
                        mp.erase(psum);
                    }
                    temp = temp->next;
                }
                mp[prefixsum]->next = head->next;
            }
            else{
                mp[prefixsum] = head;
            }
            head  = head->next;
        }
        
        ListNode* result = dummynode->next;
        delete dummynode;  // Free the dummy node memory
        return result;
    }
};
