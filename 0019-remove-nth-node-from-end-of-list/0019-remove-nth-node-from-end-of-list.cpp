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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* ah=head;
        ListNode* be=head;
        int cnt=0;
        while(cnt!=n){
            ah=ah->next;
            cnt++;
        }
        if(ah==nullptr){return head->next;}
        while(ah->next!=nullptr){
            ah=ah->next;
            be=be->next;
        }
        ListNode* nt=be->next;
        be->next=nt->next;
        return head;
    }
};