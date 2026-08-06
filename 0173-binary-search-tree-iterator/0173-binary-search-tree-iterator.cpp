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
class BSTIterator {
public:
stack<TreeNode*> st;
void pushlefts(TreeNode* rt){
    while(rt){
        st.push(rt);
        rt=rt->left;
    }
}
    BSTIterator(TreeNode* rt){
        pushlefts(rt);
    }
    
    int next(){
        TreeNode* cr=st.top();
        st.pop();
        pushlefts(cr->right);
        return cr->val;
    }
    
    bool hasNext(){
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */