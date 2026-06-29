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
int ans=INT_MIN;
int f(TreeNode* rt){
    if(rt==nullptr){return 0;}
    int ltvl=f(rt->left);
    int rtvl=f(rt->right);
    ans=max(ans,max(0,ltvl)+max(0,rtvl)+rt->val);
    return rt->val+max(max(0,rtvl),max(0,ltvl));
}
    int maxPathSum(TreeNode* rt){
        f(rt);
        return ans;
    }
};