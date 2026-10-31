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
int mx=INT_MIN;
int f(TreeNode* root){
    if(!root){return 0;}
    int left_max=f(root->left);
    int right_max=f(root->right);
    mx=max(mx,max(0,left_max)+max(0,right_max)+root->val);
    return root->val+max({left_max,right_max,0});
}
    int maxPathSum(TreeNode* root){
        f(root);
        return mx;
    }
};