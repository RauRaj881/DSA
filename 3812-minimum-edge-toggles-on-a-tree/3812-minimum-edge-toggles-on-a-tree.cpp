class Solution {
public:
void dfs(int node,int parent,vector<vector<pair<int,int>>> &adj,string &st,string &trg,vector<int> &ans,int edg){
    for(auto it:adj[node]){
        int v=it.first;
        int ed=it.second;
        if(v==parent){continue;}
        dfs(v,node,adj,st,trg,ans,ed);
    }
    if(st[node]!=trg[node]&&edg!=-1){
        int x=st[node]-'0';
        int y=st[parent]-'0';
        x^=1;y^=1;
        st[node]=x+'0';st[parent]=y+'0';
        ans.push_back(edg);
    }
}
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string st, string trg){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        vector<int> ans;
        dfs(0,-1,adj,st,trg,ans,-1);
        if(st!=trg){return {-1};}
        sort(ans.begin(),ans.end());
        return ans;
    }
};