class Solution {
public:
long long dfs(int nd,vector<vector<int>> &adj,vector<int>& bt){
    long long mx=0,mn=LLONG_MAX;;
    if(adj[nd].size()==0){return bt[nd];}
    for(auto it:adj[nd]){
        long long tp=dfs(it,adj,bt);
        mx=max(mx,tp);
        mn=min(mn,tp);
    }
    return mx-mn+bt[nd]+mx;
}
    long long finishTime(int n, vector<vector<int>>& ed,vector<int>& bt){
        vector<vector<int>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            adj[u].push_back(v);
        }
        return dfs(0,adj,bt);
    }
};