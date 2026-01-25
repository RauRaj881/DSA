class Solution {
public:
bool ispossible(long long mid,vector<vector<pair<long long,long long>>> &adj,long long k,int n){
    set<pair<long long,long long>> s;
    s.insert({0,0});
    vector<long long> mnd(n,k+1);
    while(!s.empty()){
        auto it=*s.begin();
        long long dist=it.first;
        long long nd=it.second;
        s.erase(it);
        if(nd==n-1){return true;}
        for(auto ig:adj[nd]){
            long long v=ig.first;
            long long w=ig.second;
            if(dist+w<=k&&w>=mid&&dist+w<mnd[v]){
                s.erase({mnd[v], v});
                mnd[v]=dist+w;
                s.insert({dist+w,v});
            }
        }
    }
    return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<long long,long long>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(online[v]&&online[u])adj[u].push_back({v,w});
        }
        long long low=0,high=1e9;
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,adj,k,n)){
                ans=mid;low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};