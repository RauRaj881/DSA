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
    TreeNode* lowestCommonAncestor(TreeNode* rt,TreeNode* p,TreeNode* q){
        if(rt==nullptr||rt==p||rt==q){return rt;}
    TreeNode* left=lowestCommonAncestor(rt->left,p,q);
    TreeNode* right=lowestCommonAncestor(rt->right,p,q);
    if(left!=nullptr&&right!=nullptr){return rt;}
    if(left!=nullptr){return left;}
    return right;
    }
};