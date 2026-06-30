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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},root});
        while(!q.empty()){
            auto temp=q.front();
            int x=temp.first.first;
            int y=temp.first.second;
            q.pop();
            if(temp.second->left!=nullptr){
                q.push({{x-1,y+1},temp.second->left});
            }
             if(temp.second->right!=nullptr){
                q.push({{x+1,y+1},temp.second->right});
            }
            mp[x][y].insert(temp.second->val);
        }
        vector<vector<int>> v;
        for(auto h:mp){
            vector<int> path;
            for(auto x:h.second){
                for(auto nx:x.second){
                path.push_back(nx);
                }
            }
            v.push_back(path);
        }
        return v;
    }
};