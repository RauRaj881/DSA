class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat){
        int n=mat.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                adj[i].push_back(j);}
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=adj[i].size();
        }
        return ans;
        
    }
};