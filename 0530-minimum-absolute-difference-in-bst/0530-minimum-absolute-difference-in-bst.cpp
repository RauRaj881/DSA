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
vector<int> v;
void f(TreeNode* rt){
    if(rt==nullptr){return;}
    v.push_back(rt->val);
    f(rt->left);
    f(rt->right);
}
    int getMinimumDifference(TreeNode* rt){
        f(rt);
        sort(v.begin(),v.end());
        int mn=1e6;
        for(int i=1;i<v.size();i++){
            mn=min(mn,v[i]-v[i-1]);
        }
        return mn;
    }
};