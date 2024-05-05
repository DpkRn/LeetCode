/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//standard way
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode=node->next;
        node->val=nextNode->val;
        node->next=nextNode->next;
        delete nextNode;
    }
};
/*
//not a standard way
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        while(temp->next->next){
            temp->val=temp->next->val;
            temp=temp->next;
        }
        temp->val=temp->next->val;
        temp->next=NULL;
    }
};
*/