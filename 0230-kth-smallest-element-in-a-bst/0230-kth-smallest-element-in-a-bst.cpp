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
int vl=-1;
vector<int> v;
void f(TreeNode* rt){
    if(!rt){return;}
    f(rt->left);
    v.push_back(rt->val);
    f(rt->right);
}
    int kthSmallest(TreeNode* rt,int k){
        f(rt);
       return v[k-1];
    }
};