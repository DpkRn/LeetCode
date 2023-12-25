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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
         int carry=0;
        while(l1&&l2){
            int sumOfDigits=l1->val+l2->val+carry;
            int store=sumOfDigits%10;
           
            temp->next=new ListNode(store);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next; 
            carry=sumOfDigits/10;    
        }
        while(l1) {
            int num=l1->val+carry;
            temp->next=new ListNode(num%10);
            carry=num/10;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2) {
            int num=l2->val+carry;
            temp->next=new ListNode(num%10);
             carry=num/10;
            temp=temp->next;
            l2=l2->next;
        }
        if(carry!=0)
            temp->next=new ListNode(carry);
        
        return head->next;
    }
};