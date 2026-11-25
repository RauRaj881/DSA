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
int cameras=0;
int dfs(TreeNode* root){
    if(!root){return 2;}
    int left_child=dfs(root->left);
    int right_child=dfs(root->right);
    if(left_child==0||right_child==0){cameras++;return 1;}
    else if(left_child==1||right_child==1){return 2;}
    else{return 0;}
}
    int minCameraCover(TreeNode* root){
        if(dfs(root)==0){cameras++;}
        return cameras;
    }
};