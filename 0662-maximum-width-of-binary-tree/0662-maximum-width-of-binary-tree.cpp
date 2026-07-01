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
    int widthOfBinaryTree(TreeNode* rt){
        queue<pair<TreeNode*,long long>> q;
        q.push({rt,0});
        long long mx=1;
        while(!q.empty()){
            int sz=q.size();
            long long lm,rm;
            long long df=q.front().second;
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front().first;
                long long x=q.front().second;
                x-=df;
                if(i==0){lm=x;}
                if(i==sz-1){rm=x;}
                if(nd->left!=nullptr){q.push({nd->left,2*x+1});}
                if(nd->right!=nullptr){q.push({nd->right,2*x+2});}
                q.pop();
            }
            mx=max(rm-lm+1,mx);
        }
        return mx;
        
    }
};