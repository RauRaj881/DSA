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
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* nd=pq.top();
            pq.pop();
            tail->next=nd;
            tail=nd;
            if(nd->next){pq.push(nd->next);}
        }
        return dummy->next;
    }
};