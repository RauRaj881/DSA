class Solution {
public:
bool pos=true;
void dfs(int u,int prt,vector<vector<int>>& g,vector<int>&col,int x){
    if(!pos){return;;}
    col[u]=x;
    for(auto it:g[u]){
        if(it!=prt){
            if(col[it]==x){pos=false;return;}
            else if(col[it]==-1)dfs(it,u,g,col,1-x);
        }
    }
}
    bool isBipartite(vector<vector<int>>& g){
        int n=g.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1)
        dfs(i,-1,g,col,0);
        }
        return pos;
    }
};