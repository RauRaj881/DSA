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

TreeNode* helper(TreeNode* rt){
    if(!rt->left){return rt->right;}
    else if(!rt->right){return rt->left;}
    TreeNode* lastright=f(rt->left);
    lastright->right=rt->right;
    return rt->left;
}
TreeNode* f(TreeNode* rt){
    while(rt->right){
        rt=rt->right;
    }
    return rt;
}
    TreeNode* deleteNode(TreeNode* rt, int key){
        TreeNode* cr=rt;
        TreeNode* dummy=rt;
        if(!rt){return nullptr;}
        if(rt->val==key){return helper(rt);}
        while(rt){
            if(rt->val>key){
                if(rt->left&&rt->left->val==key){
                    rt->left=helper(rt->left);
                }
                else{
                    rt=rt->left;
                }
            }
            else{
                if(rt->right&&rt->right->val==key){
                    rt->right=helper(rt->right);
                }
                else{
                    rt=rt->right;
                }
            }
        }
        return dummy;
    }
};