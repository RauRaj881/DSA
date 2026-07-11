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
        if(k==0||!head){return head;}
        int cnt=0;
        ListNode* cr=head;
        while(cr){
            cnt++;cr=cr->next;
        }
        k=k%cnt;
        if(k==0){return head;}
        int cnt2=1;
        cr=head;
        ListNode* tp=cr;
        while(cnt2!=cnt-k){
            cnt2++;
            cr=cr->next;
        }
        tp=cr->next;
        ListNode* head2=tp;
        cr->next=nullptr;
        while(tp->next){
            tp=tp->next;
        }
        tp->next=head;
        return head2;
    }
};