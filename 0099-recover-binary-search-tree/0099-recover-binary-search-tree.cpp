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
    if(!rt){return;}
    f(rt->left);
    v.push_back(rt->val);
    f(rt->right);

}
int i=0;
void f2(TreeNode* rt){
    if(!rt){return;}
    f2(rt->left);
    rt->val=v[i];i++;
    f2(rt->right);
}
    void recoverTree(TreeNode* rt){
        f(rt);
        sort(v.begin(),v.end());
        f2(rt);
    }
};