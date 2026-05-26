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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr){return nullptr;}
        ListNode* fast=head;
        ListNode* slow=head;
        int h=0;
        while(h!=n){
            fast=fast->next;h++;
        }
        if(fast==nullptr){return head->next;}
        while(fast->next!=nullptr){
            fast=fast->next;slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete(temp);
        return head;
    }
};