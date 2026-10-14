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
        while(rt){
            if(rt->val>p->val&&rt->val>q->val){
                rt=rt->left;
            }
            else if(rt->val<p->val&&rt->val<q->val){
                rt=rt->right;
            }
            else{return rt;}
        }
        return nullptr;
    }
};