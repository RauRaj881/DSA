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
    vector<int> preorderTraversal(TreeNode* rt){
        stack<TreeNode*> st;
        vector<int> ans;
        if(rt!=nullptr)st.push(rt);
        while(!st.empty()){
            TreeNode* ft=st.top();
            ans.push_back(ft->val);
            st.pop();
            if(ft->right!=nullptr){st.push(ft->right);}
            if(ft->left!=nullptr){st.push(ft->left);}
        }
        return ans;
    }
};