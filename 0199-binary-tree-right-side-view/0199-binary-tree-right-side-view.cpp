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
    vector<int> rightSideView(TreeNode* rt){
        //map<int,int> mp;
        queue<TreeNode*> q;
        if(rt!=nullptr)q.push(rt);
        vector<int> ans;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            TreeNode* nd=q.front();
            if(i==sz-1){ans.push_back(nd->val);}
            q.pop();
            //mp[x]=nd->val;
            if(nd->left!=nullptr){q.push(nd->left);}
            if(nd->right!=nullptr){q.push(nd->right);}
            }
        }
        return ans;
    }
};