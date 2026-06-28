class Solution {
public:
    vector<long long> minTimeMaxPower(int n,vector<vector<int>>& ed,int pwr, vector<int>& cst,int src,int trg){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            int tm=ed[i][2];
            adj[u].push_back({v,tm});
        }
        vector<vector<long long>> dist(n,
    vector<long long>(pwr + 1, 1e18)
);
        set<vector<long long>> st;
        st.insert({0,src,pwr});
        long long mn=1e17;
        long long mxpr=-1;
        dist[src][pwr]=0;
        while(!st.empty()){
            vector<long long> cr=*st.begin();
            st.erase(st.begin());
            long long crtm=cr[0],nd=cr[1],cpwr=cr[2];
           // if (crtm != dist[nd][cpwr]) continue;
            if(nd==trg){if(crtm<=mn){mn=crtm;mxpr=max(mxpr,(long long)cpwr);}else{break;}}
            for(auto it:adj[nd]){
                int v=it.first;
                int adtm=it.second;
                long long tsx=crtm+adtm;
                if(cst[nd]<=cpwr&&dist[v][cpwr-cst[nd]]>tsx){st.insert({tsx,v,cpwr-cst[nd]});dist[v][cpwr-cst[nd]]=tsx;}      
            }
        }
        if(mn!=1e17){return {mn,mxpr};}
        return {-1,-1};
    }
};