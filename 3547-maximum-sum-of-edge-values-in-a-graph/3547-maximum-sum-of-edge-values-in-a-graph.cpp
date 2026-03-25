class Solution {
public:
void dfs(vector<vector<int>> &adj,int n,int tp,long long &ans,int nd,vector<int>&vis,long long val){
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(vis[it]==-1){
                if(tp==1){
                    if(val<n-1){ans+=val*(val+2);dfs(adj,n,tp,ans,it,vis,val+2);}
                    else if(val==n-1){ans+=val*(n);dfs(adj,n,1-tp,ans,it,vis,n);}
                    else{ans+=val*(val-1);dfs(adj,n,1-tp,ans,it,vis,val-1);}
                }
                else{
                    ans+=val*(val-2);
                    dfs(adj,n,tp,ans,it,vis,val-2);
                }
        }
    }
}
    long long maxScore(int n, vector<vector<int>>& edges){
        vector<int> vis(n,-1);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){
                dfs(adj,n,1,ans,i,vis,1);
            }
        }
        if(ans==0){dfs(adj,n,1,ans,0,vis,1);ans+=2;}
        return ans;
    }
};