class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& ed, string lbl,int k){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            int w=ed[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );
        set<vector<long long>> st;
        st.insert({0,0,1});
        dist[0][1]=0;
        while(!st.empty()){
            auto it=*st.begin();
            int w=it[0],u=it[1],cnt=it[2];
            st.erase(st.begin());
            //if (w != dist[u][cnt]) continue;
            if(it[1]==n-1){return it[0];}
            for(auto it2:adj[u]){
                int cntp=cnt;
                int v=it2.first;
                int adw=it2.second;
                if(lbl[v]==lbl[u]){cntp++;}
                else{cntp=1;}
                if(cntp<=k){
                    long long nw = w + adw;
                    if (nw < dist[v][cntp]){
                        dist[v][cntp] = nw;
                        st.insert({nw, v, cntp});
                    }
                }
            }
        }
        return -1;
    }
};