class Solution {
public:
bool ispossible(long long mid,vector<bool>& onl,vector<vector<pair<int,int>>> &adj,long long k){
    int n=onl.size();
    set<vector<long long>> st;
    st.insert({0,0});
    vector<long long> dst(n,k+1);
    dst[0]=0;
    while(!st.empty()){
        vector<long long> it=*st.begin();
        long long w=it[0],u=it[1];
        st.erase(st.begin());
        if(u==n-1){return true;}
        for(auto it2:adj[u]){
            long long v=it2.first;
            long long adw=it2.second;
            if(w+adw<=k&&adw>=mid&&dst[v]>w+adw&&onl[v]){
                st.erase({dst[v],v});
                st.insert({w+adw,v});
                dst[v]=w+adw;
            }
        }
    }
    return false;
}
    int findMaxPathScore(vector<vector<int>>& ed,vector<bool>& onl,long long k){
        int n=onl.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0],v=ed[i][1],w=ed[i][2];
            if(onl[v]&&onl[u])adj[u].push_back({v,w});
        }
        int ans=-1;
        long long low=0,high=1e9;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,onl,adj,k)){ans=mid;low=mid+1;}
            else{high=mid-1;}
        }
        return ans;
    }
};