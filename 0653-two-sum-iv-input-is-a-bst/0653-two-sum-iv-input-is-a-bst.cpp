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
        for(int i=0;i<v.size();i++){
            auto it=lower_bound(v.begin(),v.end(),k-v[i]);
            if(it!=v.end()){
                int idx=it-v.begin();
                if(v[idx]==k-v[i]&&idx!=i){return true;}
            }
        }
        return false;
    }
};