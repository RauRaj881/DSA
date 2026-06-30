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
    bool isSymmetric(TreeNode* rt){
        TreeNode* rt1=rt->left;
        TreeNode* rt2=rt->right;
        queue<TreeNode*> q;
        q.push(rt1);
        q.push(rt2);
        while(!q.empty()){
            TreeNode* tp1=q.front();
            q.pop();
            TreeNode* tp2=q.front();
            q.pop();
            if(tp1==nullptr&&tp2==nullptr){continue;}
            if(tp1==nullptr||tp2==nullptr){return false;}
            if(tp1->val!=tp2->val){return false;}
            q.push(tp1->left);
            q.push(tp2->right);
            q.push(tp1->right);
            q.push(tp2->left);
        }
        return true;
    }
};