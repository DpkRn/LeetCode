/*
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
    ListNode* rev(ListNode* temp){
        if(temp==NULL||temp->next==NULL) return temp;
        ListNode* head=rev(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return head;
        
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;
        head=rev(head);
        ListNode* max=head;
        ListNode* curr=head->next;
        
        while(curr){
            ListNode* nextNode=curr->next;
            
            if(curr->val<max->val){
                max->next=nextNode;
                curr=curr->next;   
            }else{
                max=curr;
                curr=curr->next;
            }
           
        }
        head=rev(head);
        
       return head;
    }
};