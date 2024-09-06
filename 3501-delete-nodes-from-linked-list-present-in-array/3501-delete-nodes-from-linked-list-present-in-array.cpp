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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast!=NULL){
            if(fast->val>nums[n-1]){
                slow=fast;
                fast=fast->next;
                continue;
            }
            if(help(nums,fast->val)){
                slow->next=fast->next;
                fast=fast->next;
            }
            else{
                slow=fast;
                fast=fast->next;
            }
        }
        for(int i=0;i<n;i++){
            if(head->val==nums[i]){
                head = head->next;
            }
        }
        return head;
    }
    bool help(vector<int>& nums,int a){
        int l=0,h=nums.size()-1,mid=0;
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==a){
                return true;
            }
            else if(nums[mid]>a){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};