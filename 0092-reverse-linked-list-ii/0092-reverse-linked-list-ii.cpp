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
        if(lt==rt){return head;}
        ListNode* nd1=nullptr;
        ListNode* cr=head;
        int cnt=1;
        while(cnt<lt-1){
            cr=cr->next;
            cnt++;
        }
        if(lt!=1)nd1=cr;
        ListNode* tp;
        ListNode* cr1;
        ListNode* cr2;
        if(lt!=1){
        tp=cr->next;
        cr1=cr->next;
        }
        else{tp=head;cr1=head;}
        cr2=cr1->next;
        int cnt2=0;
        while(cnt2<rt-lt){
            ListNode* nt=cr2->next;
            cr2->next=cr1;
            cr1=cr2;
            cr2=nt;
            cnt2++;
        }
        if(nd1){nd1->next=cr1;}
        else{head=cr1;}
        tp->next=cr2;
        return head;
    }
};