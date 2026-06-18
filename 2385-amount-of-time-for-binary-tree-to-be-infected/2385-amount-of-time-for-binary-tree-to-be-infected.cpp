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
    int amountOfTime(TreeNode* root, int start){
        unordered_map<int,vector<int>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cr=q.front();
            q.pop();
            if(cr->left!=nullptr){
                mp[cr->val].push_back(cr->left->val);
                mp[cr->left->val].push_back(cr->val);
                q.push(cr->left);
            }
            if(cr->right!=nullptr){
                mp[cr->val].push_back(cr->right->val);
                mp[cr->right->val].push_back(cr->val);
                q.push(cr->right);
            }
        }
        unordered_set<int> st;
        queue<int> q2;
        q2.push(start);
        st.insert(start);
        int level=0;
        while(!q2.empty()){
            int sz=q2.size();
            for(int i=0;i<sz;i++){
                int cr=q2.front();
                q2.pop();
                for(auto it:mp[cr]){
                    if(!st.count(it)){
                        q2.push(it);
                        st.insert(it);
                    }
                }
            }
            level++;
        }
        return level-1;
    }
};