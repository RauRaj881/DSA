
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& rds){
        vector<vector<pair<ll,ll>>> adj(n);
        for(int i=0;i<rds.size();i++){
            ll u=rds[i][0];
            ll v=rds[i][1];
            ll w=rds[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        ll mod=1e9+7;
        vector<pair<ll,ll>> dst(n,{1e17,0});
        set<pair<ll,pair<ll,ll>>> st;
        st.insert({0,{0,1}});
        dst[0]={0,1};
        while(!st.empty()){
            pair<ll,pair<ll,ll>> cr=*st.begin();
            ll w=cr.first;
            ll u=cr.second.first;
            ll cnt=cr.second.second;
            st.erase(st.begin());
            if(dst[u].first!=w||dst[u].second!=cnt){continue;}
            for(auto it:adj[u]){
                ll v=it.first;
                ll nw=it.second;
                if(dst[v].first>nw+w){
                    dst[v].first=nw+w;
                    dst[v].second=cnt;
                    st.insert({nw+w,{v,cnt}});
                }
                else if(dst[v].first==nw+w){
                    ll x=(dst[v].second+cnt)%mod;
                    st.insert({nw+w,{v,x}});
                    dst[v].second=x;
                }
            }
        }
        return dst[n-1].second;
    }
};