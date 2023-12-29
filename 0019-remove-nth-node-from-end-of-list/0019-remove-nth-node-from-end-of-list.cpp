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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        //you can use this loop instead of for loop
        // while(fast){
        //     fast=fast->next;
        //     n--;
        //     if(n==0) break;               
        // }
        for(int i=0;i<n;i++) fast=fast->next;
        if(fast==NULL) return head->next;
        ListNode* slow=head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* del=slow->next;
        slow->next=del->next;
        delete(del);
        return head;
        
    }
};

/* Recursive method
class Solution {
public:
    int remove(ListNode* head,int K){
    if(head==NULL){
        return 0;
    }
    int cnt=remove(head->next,K);
    if(cnt==K){        
        head->next=head->next->next;
    }
    return cnt+1;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
   int cnt=remove(head,n);
    if(cnt==n)
    return head->next;
    return head;

    }
};
*/