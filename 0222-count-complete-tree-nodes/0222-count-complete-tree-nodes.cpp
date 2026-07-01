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
    int countNodes(TreeNode* rt){
        int ans=0;
        queue<TreeNode*> q;
        if(rt)q.push(rt);
        while(!q.empty()){
            int sz=q.size();
            ans+=sz;
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front();
                q.pop();
                if(nd->left){q.push(nd->left);}
                if(nd->right){q.push(nd->right);}
            }
        }
        return ans;
        
    }
};