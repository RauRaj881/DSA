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
    ListNode* deleteMiddle(ListNode* head){
        ListNode* ft=head;
        ListNode* sl=head;
        if(head->next==nullptr){return nullptr;}
        while(ft->next->next!=nullptr&&ft->next->next->next!=nullptr){
            ft=ft->next->next;
            sl=sl->next;
        }
        ListNode* tp=sl->next;
        sl->next=tp->next;
        return head;
    }
};