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
    ListNode* reverseList(ListNode* head) {
       
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr){
            ListNode* tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
};


/* 

O(N) O(N)

class Solution {
    ListNode* rev(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* headNode=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return headNode;       
    }
public:
    ListNode* reverseList(ListNode* head) {
        
        return rev(head);
        
    }
};

*/

/*
 O(N) O(N)
 
 
 
 class Solution {
    ListNode* rev(ListNode* head,ListNode* &ans){
        if(head->next==NULL){
            ans=head;
            return head;
        }
        ListNode* temp=rev(head->next,ans);
        temp->next=head;
        head->next=NULL;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans;
        if(head==NULL) return head;
        rev(head,ans);
        return ans;
    }
};
 
*/