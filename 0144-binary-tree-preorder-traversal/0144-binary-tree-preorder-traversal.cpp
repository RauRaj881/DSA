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
        vector<int> ans;
        stack<TreeNode*> st;
        if(rt)st.push(rt);
        while(!st.empty()){
            TreeNode* cr=st.top();
            st.pop();
            ans.push_back(cr->val);
            if(cr->right){st.push(cr->right);}
            if(cr->left){st.push(cr->left);}
        }
        return ans;
    }
};