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
    bool isMaxMin(int x,int y,int z){
        return x>y&&y<z||x<y&&y>z;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* prev=head;
        int mini=1e9,maxi=-1;
        int ind=2;
        
        int first=-1,last=-1; 
        while(curr->next!=NULL){
            ListNode* fwd=curr->next;
            if(isMaxMin(prev->val,curr->val,fwd->val)){
                if(first==-1) first=ind;
                
                mini=last!=-1?min(mini,ind-last):1e9;
                last=ind;
            }
            prev=curr;
            curr=curr->next;
            ind++;
        }
        
        //if last or first having -1 return -1,-1
        if(first==-1||mini==1e9) return {-1,-1};
        return { mini,last-first};
    }
};