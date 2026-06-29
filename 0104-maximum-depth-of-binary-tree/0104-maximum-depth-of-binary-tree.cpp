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
    int maxDepth(TreeNode* rt){
        queue<TreeNode*> q;
        if(rt!=nullptr)q.push(rt);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            level++;
            for(int i=0;i<sz;i++){
                TreeNode* ft=q.front();
                if(ft->left!=nullptr){q.push(ft->left);}
                if(ft->right!=nullptr){q.push(ft->right);}
                q.pop();
            }
        }
        return level;
    }
};