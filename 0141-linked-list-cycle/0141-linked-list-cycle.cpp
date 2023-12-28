/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//O(N) O(1) most optimised
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

/*
//using hashmap O(N) O(N)
class Solution {
public:
   
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mp;
        while(head!=NULL){
            if(mp[head]==1)
                return true;
            mp[head]=1;
            head=head->next;
        }
        return false;
    }
};
*/
