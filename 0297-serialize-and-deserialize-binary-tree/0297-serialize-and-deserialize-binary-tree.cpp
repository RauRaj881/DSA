/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* rt){
        if(!rt){return "";}
        string s="";
        queue<TreeNode*> q;
        TreeNode* tp=rt;
        q.push(tp);
        while(!q.empty()){
            TreeNode* cr=q.front();
            q.pop();
            if(cr){
                s+=to_string(cr->val)+',';
                q.push(cr->left);
                q.push(cr->right);
            }
            else{
                s+="#,";
            }
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if (data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* rt=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(rt);
        while(!q.empty()){
            TreeNode* cr=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                TreeNode* lt=new TreeNode(stoi(str));
                cr->left=lt;
                q.push(lt);
            }
            getline(s,str,',');
            if(str!="#"){
                TreeNode* rgt=new TreeNode(stoi(str));
                cr->right=rgt;
                q.push(rgt);
            }
        }
        return rt;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));