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
    vector<vector<int>> zigzagLevelOrder(TreeNode* rt){
        queue<TreeNode*> q;
        if(rt!=nullptr){q.push(rt);}
        vector<vector<int>> ans;
        int lv=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int> tp(sz);
            for(int i=0;i<sz;i++){
                TreeNode* ft=q.front();
                int idx=(lv%2==0?i:sz-1-i);
                tp[idx]=(ft->val);
                q.pop();
                if(ft->left!=nullptr){q.push(ft->left);}
                if(ft->right!=nullptr){q.push(ft->right);}
            }
            ans.push_back(tp);
            lv++;
        }
        return ans;
    }
};