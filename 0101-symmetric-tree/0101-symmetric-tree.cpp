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
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* lt=q.front();
            q.pop();
            TreeNode* rt=q.front();
            q.pop();
            if(lt == nullptr && rt == nullptr)continue;

            if(lt==nullptr||rt==nullptr||lt->val!=rt->val){return false;}

            q.push(lt->left);q.push(rt->right);
            q.push(lt->right);q.push(rt->left);
        }
        return true;
    }
};