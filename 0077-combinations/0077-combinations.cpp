class Solution {
public:
void f(int i,int n,int k,vector<int> &path,vector<vector<int>> &ans){
    if(i>n){if(path.size()==k){ans.push_back(path);}return;}
    path.push_back(i);
    f(i+1,n,k,path,ans);
    path.pop_back();
    f(i+1,n,k,path,ans);
}
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        vector<int> path;
        f(1,n,k,path,ans);
        return ans;
    }
};