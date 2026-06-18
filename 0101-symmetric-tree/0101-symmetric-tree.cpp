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
bool check(TreeNode* lt,TreeNode* rt){
    if(lt == nullptr && rt == nullptr)return true;

    if(lt == nullptr || rt == nullptr)return false;
    return lt->val==rt->val&&check(lt->left,rt->right)&&check(lt->right,rt->left);
    
}
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);   
    }
};