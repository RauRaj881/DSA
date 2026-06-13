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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* cr1=list1;
        ListNode* cr2=list2;
        if(cr1==nullptr){return cr2;}
        else if(cr2==nullptr){return cr1;}
        int vl1=list1->val;
        int vl2=list2->val;
        ListNode* prv=nullptr;
        while(cr1!=nullptr&&cr2!=nullptr){
            if(prv==nullptr){
                if(cr1->val<=cr2->val){
                    prv=cr1;
                    cr1=cr1->next;
                }
                else{prv=cr2;cr2=cr2->next;}
            }

            else{
                if(cr1->val<=cr2->val){
                    prv->next=cr1;
                    prv=cr1;
                    cr1=cr1->next;
                }
                else{
                    prv->next=cr2;
                    prv=cr2;
                    cr2=cr2->next;
                }
            }
        }


        if(cr1!=nullptr){
            prv->next=cr1;
        }
        if(cr2!=nullptr){
            prv->next=cr2;
        }
        if(vl1<=vl2){return list1;}
        return list2;
    }
};