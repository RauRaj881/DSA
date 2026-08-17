class Solution {
public:
bool dfs(int nd,vector<vector<int>>& adj,vector<int>&col,int cr){
    col[nd]=cr;
    for(auto it:adj[nd]){
        if(col[it]==-1){
            if(!dfs(it,adj,col,1-cr)){return false;}
        }
        else{
            if(col[it]==cr){return false;}
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,adj,col,0)){return false;};
            }
        }
        return true;
    }
};