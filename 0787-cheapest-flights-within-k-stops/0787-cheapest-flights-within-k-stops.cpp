class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flt,int src,int dst,int k){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flt.size();i++){
            int u=flt[i][0];
            int v=flt[i][1];
            int w=flt[i][2];
            adj[u].push_back({v,w});
        }
        set<vector<int>> st;
        st.insert({0,src,0});
        while(!st.empty()){
            auto it=*st.begin();
            int w=it[0];
            int u=it[1];
            int stp=it[2];
            st.erase(it);
            if(u==dst){return w;}
            for(auto it2:adj[u]){
                int v=it2.first;
                int adw=it2.second;
                if(stp<=k){
                    st.insert({w+adw,v,stp+1});
                }
            }
        }
        return -1;
        
    }
};