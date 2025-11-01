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
        unordered_set<int> mp;
        for(auto it:nums){
            mp.insert(it);
        }
        while(head!=nullptr&&mp.count(head->val)){
            ListNode* temp1=head;
            head=head->next;
            //delete temp1;
        }
        if(head==nullptr){return nullptr;}
        ListNode* temp=head;
        while(temp->next!=nullptr){
            if(mp.count(temp->next->val)){
                ListNode* curr=temp->next;
                temp->next=temp->next->next;
                //delete curr;
            }
            else{temp=temp->next;}
        }
        return head;
    }
};