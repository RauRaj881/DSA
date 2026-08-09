class Solution {
public:
void dfs(int nd,vector<vector<int>> &adj,vector<int>&vis){
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(vis[it]==-1){
            dfs(it,adj,vis);
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& c){
        if(c.size()<n-1){return -1;}
        int comp=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<c.size();i++){
            int u=c[i][0];
            int v=c[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){comp++;dfs(i,adj,vis);}
        }
        return comp-1;
    }
};