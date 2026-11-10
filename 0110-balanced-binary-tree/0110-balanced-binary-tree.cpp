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
bool pos=true;
int f(TreeNode* root){
    if(!root){return 0;}
    int left_height=f(root->left);
    int right_height=f(root->right);
    if(abs(left_height-right_height)>1){pos=false;}
    return 1+max(left_height,right_height);
}
    bool isBalanced(TreeNode* root){
        f(root);
        return pos;
    }
};