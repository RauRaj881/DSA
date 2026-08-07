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
struct sbtree{
    bool isbst;
    int mx;
    int mn;
    int sm;
};
int ans=0;
sbtree f(TreeNode* rt){
    if(!rt){return {true,INT_MIN,INT_MAX,0};}
    sbtree lft=f(rt->left);
    sbtree rgt=f(rt->right);
    if(lft.isbst&&rgt.isbst&&rt->val>lft.mx&&rt->val<rgt.mn){
        int sm=rgt.sm+lft.sm+rt->val;
        ans=max(ans,sm);
        int mx=max(rgt.mx,rt->val);
        int mn=min(lft.mn,rt->val);
        return {true,mx,mn,sm};
    }
    return {false,INT_MIN,INT_MAX,0};
}
    int maxSumBST(TreeNode* rt){
        f(rt);
        return ans;
    }
};