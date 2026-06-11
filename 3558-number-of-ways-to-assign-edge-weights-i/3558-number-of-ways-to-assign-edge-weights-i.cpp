class Solution {
public:
int md=1e9+7;
void dfs(int nd,vector<vector<int>> &adj,int prt,int &mxd,int x){
    for(auto it:adj[nd]){
        if(it!=prt){
            mxd=max(mxd,x+1);
            dfs(it,adj,nd,mxd,x+1);
        }
    }
}
long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) res = (res * a) % md;
            a = (a * a) % md;
            b >>= 1;
        }

        return res;
}

    int assignEdgeWeights(vector<vector<int>>& ed){
        int n=ed.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mxd=0;
        dfs(1,adj,-1,mxd,0);
        int ans=0;
        return modPow(2, mxd - 1);
    }
};