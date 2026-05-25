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
    bool isPalindrome(ListNode* head) {
       /* stack<int> st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push({temp->val});
            temp=temp->next;
        }
        temp=head;
        while(!st.empty()){
            if(st.top()==temp->val){temp=temp->next;st.pop();}
            else{return 0;}
        }
        return 1;*/
        if(head==nullptr || head->next==nullptr){return 1;}
        else if(head->next->next==nullptr && head->val!=head->next->val){return 0;}
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        //slow->next=prev;
        ListNode* second=prev;
        ListNode* first=head;
        while(second!=nullptr){
            if(first->val!=second->val){return 0;}
                first=first->next;
                second=second->next;
            }
        return 1;
    }
};