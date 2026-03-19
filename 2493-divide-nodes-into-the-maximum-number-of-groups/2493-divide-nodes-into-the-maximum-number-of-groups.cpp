class Solution {
public:
void dfs(int nd,vector<vector<int>>&adj,bool &pos,int prt,int cl,vector<int>&bipar,vector<int>&vis){
    vis[nd]=1;
    bipar[nd]=cl;
    for(auto it:adj[nd]){
        if(it==prt){continue;}
        if(vis[it]==1){if(bipar[it]==bipar[nd]){pos=true;return;}else{continue;}}
        dfs(it,adj,pos,nd,1-cl,bipar,vis);
    }
}

int clc(int nd,vector<vector<int>> &adj,int n){
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(nd);
    dist[nd]=1;
    int ans=1;
    while(!q.empty()){
            int nd=q.front();
            q.pop();
            for(auto it:adj[nd]){
                if(dist[it]==-1){
                    dist[it]=dist[nd]+1;
                    q.push(it);
                    ans=max(ans,dist[it]);
                }
            }
        }
        return ans;
}
    int magnificentSets(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       vector<int> bipar(n+1);
       vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                vis[i]=1;
                bool pos=false;
                dfs(i,adj,pos,-1,1,bipar,vis);
                if(pos){return -1;}
            }
        }
        vector<int> vis2(n+1,0);
        queue<int> q;
        int ans2=0;
        for(int i=1;i<=n;i++){
            if(vis2[i]==0){
                vis2[i]=1;
                vector<int> comp;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    comp.push_back(node);
                    for(auto it : adj[node]) {
                        if(!vis2[it]) {
                            vis2[it] = true;
                            q.push(it);
                        }
                    }
                }
                int ans=0;
                for(int i=0;i<comp.size();i++){
                    ans=max(ans,clc(comp[i],adj,n));
                }
                ans2+=ans;
            }
        }
        return ans2;
    }
};