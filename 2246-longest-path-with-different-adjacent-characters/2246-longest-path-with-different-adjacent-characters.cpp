class Solution {
public:
int maxpath=1;
int dfs(int nd,int prt,vector<vector<int>>& adj,string& s){
    int max1=0,max2=0;
    for(auto it:adj[nd]){
        if(it==prt){continue;}
        int len=dfs(it,nd,adj,s);
        if(s[nd]!=s[it]){
            if(len>max1){
                max2=max1;
                max1=len;
            }
            else if(len>max2){
                max2=len;
            }
        }
    }
    maxpath=max(maxpath,max1+max2+1);
    return max1+1;
}
    int longestPath(vector<int>& parent, string s){
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            int u=i,v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,s);
        return maxpath;
    }
};