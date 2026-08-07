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
TreeNode* prv=nullptr;
void f(TreeNode* rt){
    if(!rt){return;}
    f(rt->right);
    f(rt->left);
    rt->right=prv;
    rt->left=nullptr;
    prv=rt;
}
    void flatten(TreeNode* rt){
        f(rt);
    }
};