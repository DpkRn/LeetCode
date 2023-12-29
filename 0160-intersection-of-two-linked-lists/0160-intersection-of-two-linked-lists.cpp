/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* findNode(ListNode* gLink,ListNode* sLink,int d){
        while(d){           //making skipping greater link list node to make the both linklist equal
            d--;
            gLink=gLink->next;
        } 
        while(gLink!=sLink){    //finding common node 
            gLink=gLink->next;
            sLink=sLink->next;
        }
        return gLink;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        ListNode* temp=headA;
        int cntHeadA=0;
        while(temp){       //find headA length
            cntHeadA++;
            temp=temp->next;
        }
        temp=headB;
        int cntHeadB=0;
        while(temp){        //finding headB length
            cntHeadB++;
            temp=temp->next;
        }
        
        if(cntHeadA>cntHeadB)
            return findNode(headA,headB,cntHeadA-cntHeadB);
        else
            return findNode(headB,headA,cntHeadB-cntHeadA);
    }
};