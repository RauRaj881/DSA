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
    bool isPalindrome(ListNode* head){
        ListNode* ft=head;
        ListNode* sl=head;
        while(ft!=nullptr&&ft->next!=nullptr){
            ft=ft->next->next;
            sl=sl->next;
        }
        ListNode* prv=nullptr;
        ListNode* cr=sl;
        while(cr!=nullptr){
            ListNode* nt=cr->next;
            cr->next=prv;
            prv=cr;
            cr=nt;
        }
        ListNode* second=prv;
        ListNode* first=head;
        while(second!=nullptr){
            if(second->val!=first->val){return false;}
            second=second->next;
            first=first->next;
        }
        return true;
        
    }
};