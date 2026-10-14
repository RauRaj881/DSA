/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head){
        Node* cr=head;
        stack<Node*> q;
        if(cr)q.push(cr);
        Node* prv=nullptr;
        while(!q.empty()){
            Node* ft=q.top();
            q.pop();
            if(prv){prv->next=ft;}
            ft->prev=prv;
            prv=ft;
            if(ft->next){q.push(ft->next);}
            if(ft->child){q.push(ft->child);}
            ft->child = nullptr;
        }
        return head;
    }
};