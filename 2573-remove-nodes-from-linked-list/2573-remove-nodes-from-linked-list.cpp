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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        ListNode* front;
        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        ListNode* prev2=prev;
        int mx=prev->val;
        ListNode* curr=prev->next;
        while(curr!=nullptr){
            if(curr->val<mx){prev2->next=curr->next;curr=curr->next;}
            else{mx=curr->val;prev2=curr;curr=curr->next;}
        }
        ListNode* prev3=nullptr;
        ListNode* temp2=prev;
        ListNode* front2;
        while(temp2!=nullptr){
            front2=temp2->next;
            temp2->next=prev3;
            prev3=temp2;
            temp2=front2;
        }
        return prev3;
    }
};