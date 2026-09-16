/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> ans;
void f(int nd,int dst,int k,unordered_map<int,vector<int>>& mp,int prt){
    if(dst==k){ans.push_back(nd);return;}
    for(auto it:mp[nd]){
        if(it!=prt){
            f(it,dst+1,k,mp,nd);
        }
    }
}
    vector<int> distanceK(TreeNode* rt,TreeNode* tar,int k){
        unordered_map<int,vector<int>> mp;
        stack<TreeNode*> st;
        st.push(rt);
        while(!st.empty()){
            TreeNode* cr=st.top();
            st.pop();
            if(cr->left){
                int u=cr->val;
                int v=cr->left->val;
                mp[u].push_back(v);
                mp[v].push_back(u);
                st.push(cr->left);
            }
            if(cr->right){
                int u=cr->val;
                int v=cr->right->val;
                mp[u].push_back(v);
                mp[v].push_back(u);
                st.push(cr->right);
            }
        }
        f(tar->val,0,k,mp,-1);
        return ans;
    }
};