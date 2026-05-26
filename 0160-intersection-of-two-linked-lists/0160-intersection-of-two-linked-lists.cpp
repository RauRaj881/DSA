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
    ListNode *getIntersectionNode(ListNode *hA, ListNode *hB){
        ListNode* a=hA;
        ListNode* b=hB;
        int cnta=0;
        int cntb=0;
        while(a!=nullptr){cnta++;a=a->next;}
        while(b!=nullptr){cntb++;b=b->next;}
        if(cnta<cntb){
            int x=0;
            a=hA;
            b=hB;
            while(x!=cntb-cnta){
                b=b->next;x++;
            }
            while(b!=nullptr){
                if(b==a){return b;}
                b=b->next;a=a->next;
            }
        }
        else{
            int x=0;
            a=hA;
            b=hB;
            while(x!=cnta-cntb){
                a=a->next;x++;
            }
            while(b!=nullptr){
                if(b==a){return b;}
                b=b->next;a=a->next;
            }
        }
        return nullptr;
    }
};