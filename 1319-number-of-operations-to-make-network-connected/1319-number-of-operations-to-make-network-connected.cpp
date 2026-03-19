class Solution {
public:
void dfs(int nd,vector<int> &vis,int prt,vector<vector<int>> &adj){
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(it!=prt){
            if(vis[it]==-1)dfs(it,vis,nd,adj);
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& cn){
        int c=cn.size();
        if(c<n-1){return -1;}
        int ans=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<c;i++){
            int u=cn[i][0];
            int v=cn[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=1;
                dfs(i,vis,-1,adj);
                ans++;
            }
        }
        return ans-1;
    }
};