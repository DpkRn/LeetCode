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
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* res=dummyNode;
        while(list1&&list2){
            if(list1->val<list2->val){
                res->next=list1;
                list1=list1->next;
                
            }else{
                res->next=list2;
                list2=list2->next;
            }
                res=res->next;
        }
        
        if(list1) res->next=list1;
        else res->next=list2;
        
        return dummyNode->next;
    }
    
    ListNode* helper(vector<ListNode*> & lists,int i){
        if(i==lists.size()-1) return lists[i];
        ListNode* sortedList=helper(lists,i+1);
        return merge(lists[i],sortedList);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0 ) return NULL;
         if(lists.size()==1 ) return lists[0];
        ListNode* head=helper(lists,0);
        return head;
        
        
    }
};