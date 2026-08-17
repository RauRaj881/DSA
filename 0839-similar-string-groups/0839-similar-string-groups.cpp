class Solution {
public:
void dfs(int nd,vector<vector<int>>& adj,vector<int>& vis){
    vis[nd]=1;
    for(auto it:adj[nd]){
        if(vis[it]==-1){
            dfs(it,adj,vis);
        }
    }
}
    int numSimilarGroups(vector<string>& strs){
        int n=strs.size();
        int m=strs[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            string cr=strs[i];
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                string tp=strs[j];
                int cnt=0;
                for(int k=0;k<m;k++){if(cr[k]!=tp[k]){cnt++;}}
                if(cnt<=2){adj[i].push_back(j);}
            }
        }
        vector<int> vis(n,-1);
        int comp=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){comp++;
            dfs(i,adj,vis);}
        }
        return comp;
    }
};