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
    void reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
    }
    
    ListNode* findKthNode(ListNode* head,int k){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt==k)
                return temp;
            temp=temp->next;
        }
        return NULL;
     }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==NULL){
               if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;            
            reverse(temp);
            
            if(head==temp){
                head=kthNode;
            }else{
               prevNode->next=kthNode; 
            }
            prevNode=temp;
            temp=nextNode;
            
        }
       // cout<<head->val;
        return head;
        
    }
};