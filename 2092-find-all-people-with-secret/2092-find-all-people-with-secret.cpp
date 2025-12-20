class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fP) {
        int m=meet.size();
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0;i<m;i++){
            int u=meet[i][0];
            int v=meet[i][1];
            int time=meet[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<int> vis(n,1e9);
        vis[0]=0;vis[fP]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> st;
        st.push({0,0});st.push({fP,0});
        while(!st.empty()){
            int node=st.top().first;
            int time=st.top().second;
            st.pop();
            if (time > vis[node]) continue;
            for(auto it:adj[node]){
                int nexn=it.first;
                int t=it.second;
                if(time<=t&&vis[nexn]>t){
                    st.push({nexn,t});
                    vis[nexn]=t;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]!=1e9){ans.push_back(i);}
        }
        return ans;
    }
};