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
    if(root==nullptr){
        return;
    }
    backtrack(root->left,v);
    v.push_back(root->val);
    backtrack(root->right,v);
}*/
    
    vector<int> inorderTraversal(TreeNode* root) {
       TreeNode* curr=root;
       stack<TreeNode*> st;
       vector<int> ans;
       while(curr!=nullptr||!st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        ans.push_back(curr->val);
        curr=curr->right;
       }
       return ans;
    }
};