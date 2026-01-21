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
                tot.push_back(comp);
            }
        }
        for(int i=0;i<tot.size();i++){
            vector<int> cmp=tot[i];
            sort(cmp.begin(),cmp.end());
            string temp="";
            for(int j=0;j<cmp.size();j++)temp+=s[cmp[j]];
            sort(temp.begin(),temp.end());
            for(int j=0;j<cmp.size();j++)s[cmp[j]]=temp[j]; 
        }
        return s;
    }
};