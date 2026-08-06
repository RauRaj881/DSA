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
        if(rt->val>p->val&&rt->val>q->val){
            return lowestCommonAncestor(rt->left,p,q);
        }
        else if(rt->val<p->val&&rt->val<q->val){
            return lowestCommonAncestor(rt->right,p,q);
        }
        return rt;
    }
};