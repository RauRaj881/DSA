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
TreeNode* prev=nullptr;
    void flatten(TreeNode* rt){
        if(!rt){return;}
        flatten(rt->right);
        flatten(rt->left);
        rt->right=prev;
        rt->left=nullptr;
        prev=rt;
    }
};