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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head, *next=head->next;
        while(next){
            int val=__gcd(curr->val,next->val);
            ListNode* tmp=new ListNode(val);
            curr->next=tmp;
            tmp->next=next;
            curr=next;
            next=next->next;
        }
        return head;
    }
};