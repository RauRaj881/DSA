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
TreeNode* first=nullptr;
TreeNode* second=nullptr;
TreeNode* prv=nullptr;
void f(TreeNode* rt){
    if(!rt){return;}
    f(rt->left);
    if(prv&&prv->val>rt->val){
        if(!first){
            first=prv;second=rt;
        }
        else{
            second=rt;
        }
    }
    prv=rt;
    f(rt->right);
}
    void recoverTree(TreeNode* rt){
        f(rt);
        swap(first->val,second->val);
    }
};