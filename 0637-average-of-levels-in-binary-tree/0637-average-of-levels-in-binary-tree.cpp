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
    vector<double> averageOfLevels(TreeNode* rt){
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(rt);
        while(!q.empty()){
            double sm=0;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front();
                q.pop();
                sm+=nd->val;
                if(nd->left){q.push(nd->left);}
                if(nd->right){q.push(nd->right);}
            }
            double vl=sm/sz;
            ans.push_back(vl);
        }
        return ans;
        
    }
};