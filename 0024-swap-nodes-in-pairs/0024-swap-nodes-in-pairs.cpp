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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr=head;
        ListNode* prevNode=NULL;
        while(curr&&curr->next){
            ListNode* nextNode=curr->next;
            curr->next=nextNode->next;
            nextNode->next=curr;
           
             if(curr==head) head=nextNode;
              else  if(prevNode) prevNode->next=nextNode;
           
            prevNode=curr;
            curr=curr->next;          
            
        }
        
        return head;
        
    }
};