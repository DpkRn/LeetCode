/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* findNode(ListNode* headA,ListNode* headB){
        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        ListNode* temp=headA;
        int cntHeadA=0;
        while(temp){
            cntHeadA++;
            temp=temp->next;
        }
        temp=headB;
        int cntHeadB=0;
        while(temp){
            cntHeadB++;
            temp=temp->next;
        }
        int cnt=0;
        ListNode *tempA=headA;
        ListNode* tempB=headB;
        if(cntHeadA>cntHeadB){
            tempA=headA;
            cnt=cntHeadA-cntHeadB;
             for(int i=0;i<cnt;i++) tempA=tempA->next;
        }
        else{
            tempB=headB;
            cnt=cntHeadB-cntHeadA;
            for(int i=0;i<cnt;i++) tempB=tempB->next;
        }
       
        temp=findNode(tempA,tempB);
        return temp;
        
       
    }
};