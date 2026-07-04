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
    ListNode* reverseBetween(ListNode* head, int lt,int rt){
        ListNode* left;
        ListNode* right;
        int cnt=1;
        ListNode* tx=head;
        while(tx!=nullptr){if(cnt==lt){left=tx;}if(cnt==rt){right=tx;}tx=tx->next;cnt++;}
        ListNode* nd2=right->next;
        ListNode* cr=head;
        ListNode* nd1;
        if(left==head){nd1=nullptr;}
        else{
            while(cr->next!=left){
                cr=cr->next;
            }
            nd1=cr;
        }
        ListNode* cr1=left;
        ListNode* cr2=left->next;
        while(cr2!=nd2){
            ListNode* nt=cr2->next;
            cr2->next=cr1;
            cr1=cr2;
            cr2=nt;
        }
        left->next = nd2;

        if(nd1)
        nd1->next = cr1;
        else
        head = cr1;
        return head;
    }
};