//memoization (not passing all the test cases tle)
/*class Solution {
public:
int mintri(int x,int y,vector<vector<int>> &dp,vector<vector<int>>& triangle,int m){
    if(y>m-1 ||y>triangle[x].size()-1){return 1e9;}
    if(dp[x][y]!=-1){return dp[x][y];}
    if(x==m-1){return triangle[x][y];}
    int down=triangle[x][y]+mintri(x+1,y,dp,triangle,m);
    int diagonal=triangle[x][y]+mintri(x+1,y+1,dp,triangle,m);
    return dp[x][y]=min(down,diagonal);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++){
            dp[i].resize(triangle[i].size(),-1);
        }
        return mintri(0,0,dp,triangle,m);
    }
};*/
// tabulation (reduced recursion stack space)
/*class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        if(m==1){return triangle[0][0];}
        vector<vector<int>> dp(m,vector<int>(m,-1));
        for(int j=0;j<=m-1;j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};*/
// space optimized
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int m=triangle.size();
        vector<int> prev(m,0);
        for(int j=0;j<=m-1;j++){
            prev[j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            vector<int> curr(m,0);
            for(int j=0;j<=i;j++){
                int down=triangle[i][j]+prev[j];
                int diagonal=triangle[i][j]+prev[j+1];
                curr[j]=min(down,diagonal);
            }
            prev=curr;
        }
        return prev[0];
    }
};