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
int cnt=0;
int f(TreeNode* rt){
    if(!rt){return 0;}
    int tp1=f(rt->left);
    int tp2=f(rt->right);
    if(rt->val>=tp1&&rt->val>=tp2){cnt++;}
    return max(tp1,max(tp2,rt->val));
}
    int countDominantNodes(TreeNode* rt){
        f(rt);
        return cnt;
    }
};