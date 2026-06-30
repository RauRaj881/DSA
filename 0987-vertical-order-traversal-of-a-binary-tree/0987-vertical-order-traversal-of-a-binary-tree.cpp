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
    vector<vector<int>> verticalTraversal(TreeNode* rt){
        map<int,map<int,multiset<int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},rt});
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            TreeNode* nd=q.front().second;
            q.pop();
            mp[x][y].insert(nd->val);
            if(nd->left!=nullptr){q.push({{x-1,y+1},nd->left});}
            if(nd->right!=nullptr){q.push({{x+1,y+1},nd->right});}
        }

        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> tp;
            for(auto it2:it.second){
                for(auto it3:it2.second){
                    tp.push_back(it3);
                }
            }
            ans.push_back(tp);
        }
        return ans;
    }
};