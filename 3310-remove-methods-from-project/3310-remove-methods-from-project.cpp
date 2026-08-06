class Solution {
public:
void dfs(int nd,vector<vector<int>>& adj,unordered_set<int>& tp,vector<int>& vis){
    vis[nd]=1;
    tp.insert(nd);
    for(auto it:adj[nd]){
        if(vis[it]==-1){
            dfs(it,adj,tp,vis);
        }
    }
}
    vector<int> remainingMethods(int n, int k,vector<vector<int>>& inv){
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<int> wd(n);
        for(int i=0;i<n;i++){wd[i]=i;}
        for(int i=0;i<inv.size();i++){
            int u=inv[i][0];
            int v=inv[i][1];
            indeg[v]++;
            adj[u].push_back(v);        
        }
        vector<int> vis(n,-1);
        unordered_set<int> tp;
        dfs(k,adj,tp,vis);
        unordered_set<int> tp2=tp;
        for(int i=0;i<inv.size();i++){
            int u=inv[i][0];
            int v=inv[i][1];
            if(tp2.count(v)&&tp2.count(u)){indeg[v]--;if(indeg[v]==0){tp.erase(v);}}
            else if(tp2.count(v)&&!tp2.count(u)){return wd;}
        }
        if(indeg[k]==0&&tp.count(k)){tp.erase(k);}
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!tp2.count(i)){ans.push_back(i);}
        }
        for(auto it:tp){ans.push_back(it);}
        return ans;
    }
};