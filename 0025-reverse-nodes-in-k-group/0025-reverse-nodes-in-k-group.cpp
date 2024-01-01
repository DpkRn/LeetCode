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
    
    //it will find the kthNode;
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
    
    
    //it will reverse the seprated linklist so that kthNode would be head of reversed linkedlist
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
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head;
        ListNode* prevLast=NULL; //this variable preserve the node when temp will goto the next node to get reversed new head
        
        while(temp){
            ListNode* kthNode=findKthNode(temp,k);
            
            
            if(kthNode==NULL){
               if(prevLast) prevLast->next=temp;
                break;
            }
            
            ListNode* nextNode=kthNode->next; //preserving the nextNOde to run again
            kthNode->next=NULL;       //seprating the linkedlist to reverse      
            reverse(temp);
            
            if(head==temp){          //if there will be first linklist then we dont need to insert in prevNode
                head=kthNode;
            }else{
               prevLast->next=kthNode;  //other wise there will be available prevNode of already reversed previous linklist
            }
            prevLast=temp; //preserving the prevLastNode
            temp=nextNode;
            
        }
      
        return head;
        
    }
};