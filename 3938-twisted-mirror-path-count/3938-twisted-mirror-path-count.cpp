class Solution {
public:
int f(int i,int j,int prev,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int m,int n){
    if(i<0||i>=m||j<0||j>=n){return 0;}
    else if(i==m-1&&j==n-1){return 1;}
    int mode=1e9+7;
    if(dp[i][j][prev]!=-1){return dp[i][j][prev];}
    int down=0,right=0;
    if(grid[i][j]==0){
       down=f(i+1,j,0,grid,dp,m,n);
       right=f(i,j+1,1,grid,dp,m,n);
    }
    else{
        if(prev==0){
            right=f(i,j+1,1,grid,dp,m,n);
        }
        else{
            down=f(i+1,j,0,grid,dp,m,n);
        }
    }
    return dp[i][j][prev]=(right+down)%mode;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,0,0,grid,dp,m,n);
    }
};
