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