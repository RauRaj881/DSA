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
class cmp{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lts){
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lts.size();i++){
            if(lts[i]){pq.push(lts[i]);}
        }
        ListNode* dummy=new ListNode(0);
        ListNode* prv=dummy;
        while(!pq.empty()){
            ListNode* cr=pq.top();
            pq.pop();
            prv->next=cr;prv=cr;
            if(cr->next){pq.push(cr->next);}
        }
        return dummy->next;
    }
};