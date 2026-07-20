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
int ans=-1;
int cnt=0;
void f(TreeNode* rt,int k){
    if(!rt){return;}
    f(rt->left,k);
    cnt++;
    if(cnt==k){ans=rt->val;return;}
    f(rt->right,k);
}
    int kthSmallest(TreeNode* rt,int k){
       f(rt,k);
       return ans;
    }
};