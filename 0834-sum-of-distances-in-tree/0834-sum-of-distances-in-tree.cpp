class Solution {
public:
void dfs2(int node,int prt,vector<vector<int>> &adj,vector<int>&ans,vector<int>&s,int n){
    for(auto it:adj[node]){
        if(it!=prt){
            ans[it]=ans[node]+n-s[it]-s[it];
            dfs2(it,node,adj,ans,s,n);
        }
    }
}

void dfs(int node,int prt,vector<vector<int>> &adj,vector<int>&ans,vector<int>&s,int n){
    for(auto it:adj[node]){
        if(it!=prt){
            dfs(it,node,adj,ans,s,n);
            s[node]+=s[it];
            ans[node]+=ans[it]+s[it];
        }
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& ed){
        vector<vector<int>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> s(n,1);
        vector<int> ans(n,0);
        dfs(0,-1,adj,ans,s,n);
        dfs2(0,-1,adj,ans,s,n);
        return ans;
    }
};