// memoiazation
/*class Solution {
public:
int nofways(int x,int y,vector<vector<int>> &dp){
    if(x==0 && y==0){return 1;}
    else if(x<0 || y<0){return 0;}
    if(dp[x][y]!=-1){return dp[x][y];}
    int left=nofways(x,y-1,dp);
    int up=nofways(x-1,y,dp);
    return dp[x][y]=up+left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return nofways(m-1,n-1,dp);
    }
};*/
// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(i==0 && j==0)){
                    int up,left;
                    if(j-1<0){up=0;}
                    else{up=dp[i][j-1];}
                    if(i-1<0){left=0;}
                    else{left=dp[i-1][j];}
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};