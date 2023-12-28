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
    map<ListNode*,bool> map;
    bool hasCycle(ListNode *head) {
        
        while(head!=NULL){
            if(map[head]==true)
                return true;
            map[head]=head;
            head=head->next;
        }
        return false;
    }
};
*/