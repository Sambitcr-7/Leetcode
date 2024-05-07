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

ListNode* rev(ListNode* head){
    ListNode* cur,*aft,*prev=nullptr;
    cur=aft=head;
    while(cur){
        aft=aft->next;
        cur->next=prev;
        prev=cur;
        cur=aft;
    }
    head=prev;
    return head;
}
    ListNode* doubleIt(ListNode* head) {
        head=rev(head);
        int carry=0;
        ListNode* temp=head;
        while(true){
            int sum=(head->val*2)+carry;
            head->val=sum%10;
            carry=sum/10;
            if(!head->next)
            break;
            head=head->next;
        }
        if(carry){
            ListNode *newnode=new ListNode(carry);
            head->next=newnode;
        }
        head=rev(temp);
        return head;
    }
};