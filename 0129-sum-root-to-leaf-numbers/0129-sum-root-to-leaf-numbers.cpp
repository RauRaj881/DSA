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
void f(TreeNode* rt,int cr){
    if(!rt){return;}
    cr=cr*10+rt->val;
    if(!rt->left&&!rt->right){ans+=cr;return;}
    //cr=cr*10+rt->val;
    f(rt->left,cr);
    f(rt->right,cr);
}
    int sumNumbers(TreeNode* rt){
        f(rt,0);
        return ans;
    }
};