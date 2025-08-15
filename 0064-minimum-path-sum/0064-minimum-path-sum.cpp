//memoization
class Solution {
public:
int minps(int x,int y,vector<vector<int>>& grid,vector<vector<int>> &dp){
    if(x==0 &&y==0){return grid[0][0];}
    if(x<0||y<0){return 1e9;}
    if(dp[x][y]!=-1){return dp[x][y];}
    int up=minps(x-1,y,grid,dp)+grid[x][y];
    int left=minps(x,y-1,grid,dp)+grid[x][y];
    return dp[x][y]=min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return minps(m-1,n-1,grid,dp);
    }
};