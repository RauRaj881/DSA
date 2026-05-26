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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        //int sm=0;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr||carry>0){
            int sm=carry;
            if(l1!=nullptr){
                sm+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sm+=l2->val;
                l2=l2->next;
            }
            if(sm>=10){carry=1;}
            else{carry=0;}
            ListNode* nt=new ListNode(sm%10);
            tail->next=nt;
            tail=nt;
        } 
        return dummy->next;
    }
};