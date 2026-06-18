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
    vector<int> distanceK(TreeNode* root, TreeNode* target,int k){
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cr=q.front();
            q.pop();
            if(cr->left!=nullptr){
                mp[cr].push_back(cr->left);
                mp[cr->left].push_back(cr);
                q.push(cr->left);
            }
            if(cr->right!=nullptr){
                mp[cr].push_back(cr->right);
                mp[cr->right].push_back(cr);
                q.push(cr->right);
            }
        }
        unordered_set<TreeNode*> st;
        q.push(target);
        st.insert(target);
        int level=0;
        while(!q.empty()){
            if(level==k){break;}
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* cr=q.front();
                q.pop();
                for(auto it:mp[cr]){
                    if(!st.count(it)){
                        q.push(it);
                        st.insert(it);
                    }
                }
            }
            level++;
        }
        vector<int> ans;
        while(!q.empty()){
            int vl=q.front()->val;
            ans.push_back(vl);
            q.pop();
        }
        return ans;
        
    }
};