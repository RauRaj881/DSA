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
    ListNode* sortList(ListNode* head){
        vector<int> v;
        ListNode* cr=head;
        while(cr!=nullptr){
            v.push_back(cr->val);
            cr=cr->next;
        }
        sort(v.begin(),v.end());
        cr=head;
        int idx=0;
        while(cr!=nullptr){
            cr->val=v[idx];
            idx++;cr=cr->next;
        }
        return head;
    }
};