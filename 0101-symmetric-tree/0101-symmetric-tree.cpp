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
bool f(TreeNode* rt1,TreeNode* rt2){
    if(rt1==nullptr&&rt2==nullptr){return true;}
    if(rt1==nullptr||rt2==nullptr){return false;}
    if(rt1->val!=rt2->val){return false;}
    return f(rt1->left,rt2->right)&&f(rt1->right,rt2->left);
}
    bool isSymmetric(TreeNode* rt){
        TreeNode* rt1=rt->left;
        TreeNode* rt2=rt->right;
        return f(rt1,rt2);
    }
};