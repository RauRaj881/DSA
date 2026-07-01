/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* f(TreeNode* rt, TreeNode* p, TreeNode* q){
    if(rt==nullptr||rt==p||rt==q){return rt;}
    TreeNode* left=f(rt->left,p,q);
    TreeNode* right=f(rt->right,p,q);
    if(left!=nullptr&&right!=nullptr){return rt;}
    if(left!=nullptr){return left;}
    return right;
}
    TreeNode* lowestCommonAncestor(TreeNode* rt, TreeNode* p, TreeNode* q){
        if(rt==p||rt==q){return rt;}
        return f(rt,p,q);
    }
};