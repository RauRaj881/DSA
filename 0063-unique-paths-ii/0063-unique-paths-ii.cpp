//tabulation
/*class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]!=1)dp[0][0]=1;
        else{return 0;}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(i==0 && j==0)){
                    if(obstacleGrid[i][j]==1){dp[i][j]=0;continue;}
                    else{
                        int up=0;
                        int left=0;
                        if(i>0){left=dp[i-1][j];}
                        if(j>0){up=dp[i][j-1];}
                        dp[i][j]=up+left;
                    }
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};*/
// memoiazation
/*class Solution {
public:
int nofways(int x,int y, vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
    if(x==0&&y==0){return 1;}
    else if(x<0||y<0){return 0;}
    if(dp[x][y]!=-1){return dp[x][y];}
    if(obstacleGrid[x][y]==1){return dp[x][y]=0;}
    int up=nofways(x-1,y,dp,obstacleGrid);
    int left=nofways(x,y-1,dp,obstacleGrid);
    return dp[x][y]=up+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){return 0;}
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return nofways(m-1,n-1,dp,obstacleGrid);
    }
};*/
// space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> prev(n,0);
        if(obstacleGrid[0][0]==1){return 0;}
        for(int i=0;i<m;i++){
             vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){curr[j]=0;continue;}
                if(i==0&&j==0){curr[j]=1;continue;}
                int up=0,left=0;
                if(i>0){up=prev[j];}
                if(j>0){left=curr[j-1];}
                curr[j]=up+left;
            }
            prev=curr;
        }
        return prev[n-1];  
    }
};