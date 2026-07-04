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
    ListNode* reverseList(ListNode* head){
        if(!head||!head->next){return head;}
        ListNode* cr1=head;
        ListNode* cr2=head->next;
        head->next=nullptr;
        while(cr2!=nullptr){
            ListNode* nt=cr2->next;
            cr2->next=cr1;
            cr1=cr2;
            cr2=nt; 
        }
        return cr1;
    }
};