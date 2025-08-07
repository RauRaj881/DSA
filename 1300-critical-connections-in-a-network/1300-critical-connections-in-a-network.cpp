class Solution {
public:
void dfs(int timer,int node,int parent,vector<vector<int>>& adj, vector<int> &visited,vector<vector<int>> & bridges,int tin[],int low[]){
    visited[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent){continue;}
        if(visited[it]==0){
            dfs(timer,it,node,adj,visited,bridges,tin,low);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                bridges.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int tin[n];
        int low[n];
        vector<int> visited(n,0);
        vector<vector<int>> bridges;
                dfs(0,0,-1,adj,visited,bridges,tin,low);
                return bridges;
    }
};