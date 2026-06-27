class Solution {
public:
void dfs2(int node,int parent,vector<int> &ans,vector<vector<int>> &adj, vector<int> &s,int n){
    for(auto it:adj[node]){
        if(it==parent){continue;}
        ans[it]=ans[node]-2*s[it]+n;
        dfs2(it,node,ans,adj,s,n);
    }
}
void dfs(int node,int parent,vector<int> &ans,vector<vector<int>> &adj, vector<int> &s,int n){
    for(auto it:adj[node]){
        if(it==parent){continue;}
        dfs(it,node,ans,adj,s,n);
        s[node]+=s[it];
        ans[node]+=ans[it]+s[it];
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n,0);
        vector<int> s(n,1);
        dfs(0,-1,ans,adj,s,n);
        dfs2(0,-1,ans,adj,s,n);
        return ans;
    }
};