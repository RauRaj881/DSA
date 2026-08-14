class Solution {
public:
int mx=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(vector<vector<int>>& vis,vector<vector<int>>& grid,int i,int j,int & cnt){
    int n=grid.size();
    int m=grid[0].size();
    cnt++;
    vis[i][j]=1;
    mx=max(mx,cnt);
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni<0||ni>=n||nj<0||nj>=m||vis[ni][nj]==1||grid[ni][nj]==0)continue;
        dfs(vis,grid,ni,nj,cnt);
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1&&grid[i][j]==1){
                    int cnt=0;
                    dfs(vis,grid,i,j,cnt);
                }
            }
        }
        return mx;       
    }
};