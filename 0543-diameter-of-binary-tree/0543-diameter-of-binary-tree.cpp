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
int mx=0;
int f(TreeNode* root){
    if(!root){return 0;}
    int left_height=f(root->left);
    int right_height=f(root->right);
    mx=max(left_height+right_height,mx);
    return max(left_height+1,right_height+1);
}
    int diameterOfBinaryTree(TreeNode* root){
        f(root);
        return mx;
        
    }
};