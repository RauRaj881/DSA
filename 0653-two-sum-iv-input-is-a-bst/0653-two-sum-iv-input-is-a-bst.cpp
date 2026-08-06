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
    bool findTarget(TreeNode* rt, int k){
        f(rt);
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k){return true;}
            else if(v[i]+v[j]>k){j--;}
            else{i++;}
        }
        return false;
    }
};