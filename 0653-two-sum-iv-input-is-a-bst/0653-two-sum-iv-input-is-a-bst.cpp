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
vector<int> inorder;
void solve(TreeNode* root){
    if(!root){return;}
    solve(root->left);
    inorder.push_back(root->val);
    solve(root->right);
}
    bool findTarget(TreeNode* root, int k){
        solve(root);
        int i=0,j=inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]==k){return true;}
            else if(inorder[i]+inorder[j]>k){j--;}
            else{i++;}
        }
        return false;
    }
};