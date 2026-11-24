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
pair<int,int> f(TreeNode* root){
    if(!root){return {0,0};}
    pair<int,int> left_subtree=f(root->left);
    pair<int,int> right_subtree=f(root->right);
    int robcurrent=root->val+left_subtree.second+right_subtree.second;
    int skipcurrent=max(left_subtree.second,left_subtree.first)+max(right_subtree.second,right_subtree.first);
    return {robcurrent,skipcurrent};
}
    int rob(TreeNode* root){
        pair<int,int> result=f(root);
        return max(result.first,result.second);
    }
};