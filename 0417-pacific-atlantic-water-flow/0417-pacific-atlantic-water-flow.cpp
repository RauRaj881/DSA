class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int r,int c,vector<vector<int>>& h,vector<vector<int>>& ocn){
    ocn[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dx[i];
        int nc=c+dy[i];
        if(nr<0||nr>=h.size()||nc<0||nc>=h[0].size()||ocn[nr][nc]==1||h[nr][nc]<h[r][c]){continue;}
        dfs(nr,nc,h,ocn);
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h){
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> pac(n,vector<int>(m,-1));
        vector<vector<int>> atl(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dfs(0,j,h,pac);
            dfs(n-1,j,h,atl);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,h,pac);
            dfs(i,m-1,h,atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j]==1&&pac[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};