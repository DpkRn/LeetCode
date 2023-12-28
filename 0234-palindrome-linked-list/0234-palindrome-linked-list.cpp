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
    ListNode* reverse(ListNode *head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
       
        ListNode* slow=head;
        ListNode* fast=head;
       
        
       
        while(fast->next&&fast->next->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next;
        }
        ListNode *newHead=reverse(slow->next);
        ListNode* curr=head;
        while(newHead){
            if(curr->val!=newHead->val)
                return 0;
            curr=curr->next;
            newHead=newHead->next;
        }
        return 1;
    }
};

/*
//O(N) O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(st.top()!=temp->val)
                return 0;
            st.pop();
            temp=temp->next;
        }
        return 1;
    }
};
*/