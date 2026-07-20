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
    TreeNode* insertIntoBST(TreeNode* root, int vl){
        TreeNode* cr=root;
        if(!cr){return new TreeNode(vl);}
        int tp=0;
        TreeNode* lt=nullptr;;
        while(cr){
            lt=cr;
            if(cr->val>vl){cr=cr->left;}
            else if(cr->val<vl){cr=cr->right;}
        }
        if(lt->val>vl){lt->left=new TreeNode(vl);}
        else{lt->right=new TreeNode(vl);}
        return root;
    }
};