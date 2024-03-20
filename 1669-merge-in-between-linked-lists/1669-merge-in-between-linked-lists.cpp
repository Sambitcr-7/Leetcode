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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode*ptr=list1;
        ListNode*ptr2=list1;
        int count=0;
        while(count<a-1)
        {
            ptr=ptr->next;
            count++;
        }
        count=0;
        while(count<b+1)
        {
            ptr2=ptr2->next;
            count++;
        }   
        ptr->next=list2;
        ListNode* temp=list2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr2;
        return list1;
    }
};