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
bool f(TreeNode* rt,long long mn,long long mx){
    if(!rt){return true;}
    if(rt->val>=mx||rt->val<=mn){return false;}
    return f(rt->left,mn,rt->val)&&f(rt->right,rt->val,mx);
}
    bool isValidBST(TreeNode* rt){
        return f(rt,-1e10,1e10);
    }
};