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
int ans=0;
void dfs(TreeNode* root,int targetSum,unordered_map<long long,int> mp,long long sum){
    if(!root){
        return;
    }
    sum+=root->val;
    ans+=mp[sum-targetSum];
    mp[sum]++;
    dfs(root->left,targetSum,mp,sum);
    dfs(root->right,targetSum,mp,sum);
    mp[sum]--;
    sum-=root->val;
}
    int pathSum(TreeNode* root, int targetSum){
        unordered_map<long long,int> mp;
        mp[0]=1;
        dfs(root,targetSum,mp,0);
        return ans;
    }
};