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
/*void backtrack(TreeNode* root,vector<int> &v){
    if(root==nullptr){return;}
    backtrack(root->left,v);
    backtrack(root->right,v);
    v.push_back(root->val);
}*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        if(root==nullptr){return v;}
        TreeNode* current=root;
        while(!st1.empty()){
            current=st1.top();
            st1.pop();
            st2.push(current);
            if(current->left!=nullptr){st1.push(current->left);}
            if(current->right!=nullptr){st1.push(current->right);}
        }
        while(!st2.empty()){
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
    }
};