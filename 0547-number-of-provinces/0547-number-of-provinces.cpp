class Solution {
public:
void dfs(int i,vector<int>& vis,vector<vector<int>> &adj){
    vis[i]=1;
    for(auto it:adj[i]){
        if(vis[it]==1){continue;}
        dfs(it,vis,adj);
    }
}
    int findCircleNum(vector<vector<int>>& ic){
        int n=ic.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<ic[i].size();j++){
                if(ic[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;

        
    }
};