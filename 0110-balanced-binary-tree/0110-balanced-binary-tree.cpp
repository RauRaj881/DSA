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
int f(TreeNode* rt){
    if(rt==nullptr){return 0;}
    int lh=f(rt->left);
    if(lh==-1){return -1;}
    int rh=f(rt->right);
    if(rh==-1){return -1;}
    if(abs(rh-lh)>1){return -1;}
    return 1+max(lh,rh);
}
    bool isBalanced(TreeNode* rt){
        return f(rt)!=-1;
    }
};