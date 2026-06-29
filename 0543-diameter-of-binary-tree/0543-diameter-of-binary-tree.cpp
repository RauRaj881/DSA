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
int ans=0;
int f(TreeNode* rt){
    if(rt==nullptr){return 0;}
    int lh=f(rt->left);
    int rh=f(rt->right);
    ans=max(ans,lh+rh);
    return max(1+lh,1+rh);
}
    int diameterOfBinaryTree(TreeNode* rt){
        f(rt);
        return ans;
    }
};