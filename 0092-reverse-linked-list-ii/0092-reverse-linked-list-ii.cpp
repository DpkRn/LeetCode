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
    ListNode* rev(ListNode* first,ListNode* last,ListNode* nextLast){
        if(first==last) return last;
        ListNode* lastNode=rev(first->next,last,nextLast);
        first->next->next=first;
        first->next=nextLast;
        return lastNode;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right-left==0) return head;
        ListNode* first=head;
        ListNode* prev=NULL;
        for(int i=1;i<left;i++) {prev=first; first=first->next; }
        int cntLast=right-left;
        ListNode* last=first;
        for(int i=0;i<cntLast;i++) last=last->next;
        ListNode* nextLast=last->next;
        if(prev==NULL)
            head=rev(first,last,nextLast);
        else
            prev->next=rev(first,last,nextLast);
        return head;
        
    }
};