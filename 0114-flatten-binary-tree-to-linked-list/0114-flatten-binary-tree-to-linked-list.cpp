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
    void flatten(TreeNode* rt){
        if(!rt||(!rt->left&&!rt->right)){return;}
        stack<TreeNode*> st;
        if(rt->right)st.push(rt->right);
        if(rt->left)st.push(rt->left);
        TreeNode* prv=rt;
        while(!st.empty()){
            TreeNode* cr=st.top();
            st.pop();
            prv->right=cr;
            prv->left = nullptr;
            if(cr->right){st.push(cr->right);}
            if(cr->left){st.push(cr->left);}
            prv=cr;
        }
    }
};