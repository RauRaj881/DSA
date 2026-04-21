class Solution {
public:
void dfs(int i,unordered_map<int,int> &mp,vector<int>& tar,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ind){
    vis[i]=1;
    mp[tar[i]]++;
    ind.push_back(i);
    for(auto it:adj[i]){
        if(vis[it]==-1){
            dfs(it,mp,tar,adj,vis,ind);
        }
    }
}
    int minimumHammingDistance(vector<int>& src,vector<int>& tar,vector<vector<int>>& Swp){
        int n=src.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<Swp.size();i++){
            int a=Swp[i][0];
            int b=Swp[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=0;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vector<int> ind;
                unordered_map<int,int> mp;
                dfs(i,mp,tar,adj,vis,ind);
                for(int i=0;i<ind.size();i++){
                    int idx=ind[i];
                    if(mp[src[idx]]>0){mp[src[idx]]--;}
                    else{ans++;}
                }
            }
        }
        return ans;
    }
};