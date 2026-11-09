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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=0;
        ListNode* curr=head;
        while(curr){
            sz++;
            curr=curr->next;
        }
        int tot=sz/k;
        int rem=sz%k;
        vector<ListNode*> ans(k,nullptr);
        curr=head;
        for(int i=0;i<k;i++){
            if(!curr){continue;}
            ans[i]=curr;
            int cnt=tot+(i<rem?1:0);
            for(int x=1;x<cnt;x++){
                curr=curr->next;
            }
            ListNode* next_start=curr->next;
            curr->next=nullptr;
            curr=next_start;
        }
        return ans;
    }
};