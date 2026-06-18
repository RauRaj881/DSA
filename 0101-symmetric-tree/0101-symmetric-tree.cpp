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
    if(lt==nullptr){
        if(rt==nullptr){return 1;}
        else return 0;
    }
    if(rt==nullptr){
        if(lt==nullptr){return 1;}
        else return 0;
    }
    if(lt->val==rt->val&&check(lt->left,rt->right)&&check(lt->right,rt->left)){
        return true;
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);   
    }
};