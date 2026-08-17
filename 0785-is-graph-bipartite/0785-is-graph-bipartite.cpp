class Solution {
public:
void dfs(int nd,vector<vector<int>>& adj,vector<int>& vis,vector<int>&col,int cr,bool &pos){
    vis[nd]=1;
    col[nd]=cr;
    for(auto it:adj[nd]){
        if(vis[it]==-1){
            dfs(it,adj,vis,col,1-cr,pos);
        }
        else{
            if(col[it]==cr){pos=false;return;}
        }
    }

}
    bool isBipartite(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> vis(n,-1);
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                bool pos=true;
                dfs(i,adj,vis,col,0,pos);
                if(!pos){return false;}
            }
        }
        return true;
    }
};