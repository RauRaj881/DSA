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
vector<int> v;
void f(TreeNode* rt){
    if(!rt){return;}
    f(rt->left);
    v.push_back(rt->val);
    f(rt->right);
}
int i=0;
    BSTIterator(TreeNode* rt){
        f(rt);
    }
    
    int next(){
        int cr=i;
        i++;
        return v[cr];
    }
    
    bool hasNext(){
        return i<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */