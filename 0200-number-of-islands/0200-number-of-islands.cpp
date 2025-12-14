class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};
void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]=='1'&&vis[nrow][ncol]==-1){
            dfs(nrow,ncol,vis,grid);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1&&grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt; 
    }
};