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
    ListNode* reverseKGroup(ListNode* head, int k){
        if(k==1){return head;}
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* mn=dummy;
        ListNode* pvg=dummy;
        while(mn){
            for(int i=0;i<k&&mn;i++){
                mn=mn->next;
            }
            if(!mn){break;}
            ListNode* ntg=mn->next;
            ListNode* prv=mn->next;
            ListNode* cr=pvg->next;
            ListNode* crg=pvg->next;
            while(cr!=ntg){
                ListNode* nt=cr->next;
                cr->next=prv;
                prv=cr;
                cr=nt;
            }
            pvg->next=mn;
            pvg=crg;
            mn=pvg;
        }
        return dummy->next;
    }
};