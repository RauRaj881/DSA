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
void f(TreeNode* rt,vector<int>&ans){
    if(rt==nullptr){return;}
    ans.push_back(rt->val);
    f(rt->left,ans);
    f(rt->right,ans);
}
    vector<int> preorderTraversal(TreeNode* rt){
        vector<int> ans;
        f(rt,ans);
        return ans;
    }
};