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
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        int value=0,carry=0;
        head=rev(head);
        ListNode* temp=head;
        while(temp){
            int node=2*temp->val+carry;
            temp->val=(node%10);
            carry=node/10;
            temp=temp->next;
        }       
        head=rev(head);
        if(carry>0){
        ListNode* n=head;
        head=new ListNode(carry);
        head->next=n;
        }
       
        return head;
    }
};