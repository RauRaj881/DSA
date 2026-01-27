class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pf) {
        int n=pf.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int tm=edges[i][2];
            adj[u].push_back({v,tm});
            adj[v].push_back({u,tm});
        }
        set<pair<int,pair<int,int>>> s;
        vector<int> vis(n,1e6);
        vis[0]=1;
        s.insert({pf[0],{0,0}});
        while(!s.empty()){
            auto it=*s.begin();
            int ct=it.first;
            int tm=it.second.first;
            int nd=it.second.second;
            if(nd==n-1){return ct;}
            s.erase(it);
            for(auto ix:adj[nd]){
                int nexnd=ix.first;
                int nextm=ix.second;
                if(vis[nexnd]>nextm+tm){
                    vis[nexnd]=nextm+tm;
                    if(tm+nextm<=maxTime){
                        s.insert({pf[nexnd]+ct,{nextm+tm,nexnd}});
                    }
                }
            }
        }
        return -1;
    }
};