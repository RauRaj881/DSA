class Solution {
public:
int f(int nd,vector<vector<pair<int,int>>>& adj,int dT){
    int n=adj.size();
    int ans=0;
    set<vector<int>> st;
    vector<int> vis(n,-1);
    st.insert({0,nd});
    vector<int> dst(n,INT_MAX);
    dst[nd]=0;
    vis[nd]=1;
    while(!st.empty()){
        vector<int> tp=*st.begin();
        int w=tp[0],u=tp[1];
        st.erase(st.begin());
        if(dst[u]!=w){continue;}
        for(auto it:adj[u]){
            int v=it.first;
            int adw=it.second;
            if(dst[v]>adw+w&&adw+w<=dT){
                vis[v]=1;
                dst[v]=adw+w;
                st.insert({w+adw,v});
            }
        }
    }
    for(int i=0;i<n;i++){if(vis[i]==1){ans++;}}
    return ans-1;
}
    int findTheCity(int n, vector<vector<int>>& ed, int dT){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            int w=ed[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int mn=n+1,ans=-1;
        for(int i=0;i<n;i++){
            int x=f(i,adj,dT);
            if(x<=mn){mn=x;ans=i;}
        }
        return ans;
    }
};