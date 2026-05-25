/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head){
        ListNode* ft=head;
        ListNode* sl=head;
        while(ft!=nullptr&&ft->next!=nullptr){
            ft=ft->next->next;
            sl=sl->next;
            if(ft==sl){return true;}
        }
        return 0;
        
    }
};