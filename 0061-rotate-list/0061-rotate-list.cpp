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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
       ListNode* tail=head;
        int cnt=1;
        while(tail->next){
            cnt++;
            if(cnt==1) break;
            tail=tail->next;
        }
        tail->next=head;
        ListNode* temp=head;
        
        k=k%cnt;
        int last=cnt-k;
        while(last>1){
            last--;
            temp=temp->next;
        }
        if(temp->next) head=temp->next;
        temp->next=NULL;
        return head;
        
    }
};