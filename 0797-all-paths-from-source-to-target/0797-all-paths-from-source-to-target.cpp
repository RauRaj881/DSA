class Solution {
public:
vector<vector<int>> ans;
void dfs(int nd,vector<vector<int>>& adj,vector<int>& tp,int n){
    tp.push_back(nd);
    if(nd==n-1){ans.push_back(tp);return;}
    for(auto it:adj[nd]){
        dfs(it,adj,tp,n);
        tp.pop_back();
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g){
        int n=g.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                adj[i].push_back(g[i][j]);
            }
        }
        vector<int> tp;
        dfs(0,adj,tp,n);
        return ans;
    }
};