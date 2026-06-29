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
            vector<int> tp;
            for(int i=0;i<sz;i++){
                TreeNode* ft=q.front();
                tp.push_back(ft->val);
                q.pop();
                if(ft->left!=nullptr){q.push(ft->left);}
                if(ft->right!=nullptr){q.push(ft->right);}
            }
            if(lv%2==1){reverse(tp.begin(),tp.end());}
            ans.push_back(tp);
            lv++;
        }
        return ans;
    }
};