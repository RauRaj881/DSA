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
int f(TreeNode* rt){
    if(!rt){return 0;}
    int lefth=clclh(rt);
    int righth=clcrh(rt);
    if(lefth==righth){return (1<<lefth)-1;}
    return 1+f(rt->left)+f(rt->right);
}
int clclh(TreeNode* rt){
    TreeNode* cr=rt;
    int h=0;
    while(cr){
        cr=cr->left;
        h++;
    }
    return h;
}
int clcrh(TreeNode* rt){
    TreeNode* cr=rt;
    int h=0;
    while(cr){
        cr=cr->right;
        h++;
    }
    return h;
}
    int countNodes(TreeNode* rt){
        return f(rt);
    }
};