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
    int minDepth(TreeNode* root) {
        if(!root){return 0;}
        int left_height=minDepth(root->left);
        int right_height=minDepth(root->right);
        if(!root->left) return right_height + 1;
        if(!root->right) return left_height + 1;
        return min(left_height,right_height)+1;
    }
};