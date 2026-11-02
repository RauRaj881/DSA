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
int dfs(TreeNode* root){
    if(!root){return 0;}
    int len1=dfs(root->left);
    int len2=dfs(root->right);
    int x1=0,x2=0;
    if(root->left&&root->val==root->left->val){x1=len1+1;}
    if(root->right&&root->val==root->right->val){x2=len2+1;}
    mx=max(mx,x1+x2);
    return max(x1,x2);
}
    int longestUnivaluePath(TreeNode* root){
        dfs(root);
        return mx;
    }
};