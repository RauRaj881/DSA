/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* rt){
        queue<Node*> q;
        if(rt)q.push(rt);
        while(!q.empty()){
            int sz=q.size();
            Node* prv=q.front();
            if(prv->left){q.push(prv->left);}
            if(prv->right){q.push(prv->right);}
            q.pop();
            for(int i=1;i<sz;i++){
                Node* cr=q.front();
                if(cr->left){q.push(cr->left);}
                if(cr->right){q.push(cr->right);}
                prv->next=cr;
                prv=cr;
                q.pop();
            }
            prv->next=nullptr;
        }
        return rt;
        
    }
};