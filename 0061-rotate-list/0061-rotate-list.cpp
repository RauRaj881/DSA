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
    ListNode* rotateRight(ListNode* head, int k){
        if(!head||!head->next){return head;}
        int sz=0;
        ListNode* cr=head;
        ListNode* lt=head;
        while(cr){
            sz++;
            lt=cr;
            cr=cr->next;
        }
        k%=sz;
        if(k==0){return head;}
        int trg=sz-k;
        cr=head;
        int cnt=0;
        ListNode* ori=head;
        while(cnt<trg){
            cnt++;
            if(cnt==trg){
                ori=cr->next;
                cr->next=nullptr;
                break;
            }
            cr=cr->next;
        }
        lt->next=head;
        return ori;
    }
};