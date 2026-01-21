class Solution {
public:
void dfs(int idx,vector<vector<int>> &adj,vector<int> &vis,vector<int> &comp){
    vis[idx]=1;
    comp.push_back(idx);
    for(auto it:adj[idx]){
        if(vis[it]==-1){
            dfs(it,adj,vis,comp);
        }
    }
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<vector<int>> adj(n);
        int p=pairs.size();
        for(int i=0;i<p;i++){
            int u=pairs[i][0];
            int v=pairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> tot;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vector<int> comp;
                dfs(i,adj,vis,comp);
                sort(comp.begin(),comp.end());
                string temp="";
                for(int j=0;j<comp.size();j++)temp+=s[comp[j]];
                sort(temp.begin(),temp.end());
                for(int j=0;j<comp.size();j++)s[comp[j]]=temp[j]; 
            }
        }
        return s;
    }
};