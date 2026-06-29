/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool f(TreeNode* p, TreeNode* q){
    if(p==nullptr&&q==nullptr){return true;}
    else if(p==nullptr||q==nullptr){return false;}
    bool cr=f(p->left,q->left);
    if(cr==false){return false;}
    bool cr2=f(p->right,q->right);
    if(cr2==false){return false;}
    return p->val==q->val;
}
    bool isSameTree(TreeNode* p, TreeNode* q){
        return f(p,q);
    }
};