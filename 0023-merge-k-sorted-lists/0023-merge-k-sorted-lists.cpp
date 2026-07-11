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
    ListNode* mergeKLists(vector<ListNode*>& lts){
        vector<int> v;
        for(int i=0;i<lts.size();i++){
            ListNode* cr=lts[i];
            while(cr){v.push_back(cr->val);cr=cr->next;}
        }
        sort(v.begin(),v.end());
        if(v.empty()){return nullptr;}
        ListNode* head=new ListNode(v[0]);
        ListNode* cr=head;
        for(int i=1;i<v.size();i++){
            ListNode* tp=new ListNode(v[i]);
            cr->next=tp;
            cr=tp;
        }
        return head;
    }
};