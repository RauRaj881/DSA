class Solution {
public:
void dfs(int nd,vector<vector<int>> &adj,vector<int>& vis,vector<int>&id,int i){
    id[nd]=i;
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(vis[it]==-1){
            dfs(it,adj,vis,id,i);
        }
    }
}
    vector<int> processQueries(int n,vector<vector<int>>& cn,vector<vector<int>>& qr){
        vector<vector<int>> adj(n);
        for(int i=0;i<cn.size();i++){
            int u=cn[i][0]-1;
            int v=cn[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> id(n,-1);
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,adj,vis,id,i);
            }
        }
        unordered_map<int,set<int>> mp;
        for(int i=0;i<n;i++){
            mp[id[i]].insert(i);
        }
        vector<int> ans;
        for(int i=0;i<qr.size();i++){
            int tp=qr[i][0];
            int nd=qr[i][1]-1;
            if(tp==2){
                mp[id[nd]].erase(nd);
            }
            else{
                if(mp[id[nd]].count(nd)){ans.push_back(nd+1);}
                else if(mp[id[nd]].empty()){ans.push_back(-1);}
                else{ans.push_back(*mp[id[nd]].begin()+1);}
            }
        }
        return ans;
    }
};