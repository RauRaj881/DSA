//space optimized
/*class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+prev[j];
                int leftd=matrix[i][j]+1e7;
                int rightd=matrix[i][j]+1e7;
                if(j>0){leftd=matrix[i][j]+prev[j-1];}
                if(j<n-1){rightd=matrix[i][j]+prev[j+1];}
                curr[j]=min(min(leftd,rightd),down);
            }
            prev=curr;
        }
        int minno=INT_MAX;
        for(int i=0;i<n;i++){
            minno=min(prev[i],minno);
        }
        return minno;
    }
};*/
// memoization(tle for larger n because of tc n^2 and recursion stack space)
/*class Solution {
public:
int minfallp(int x,int y,vector<vector<int>>& matrix, vector<vector<int>> &dp,int n){
    if(y<0||y>n-1){return 1e7;}
    if(x==n-1){return matrix[x][y];}
    if(dp[x][y]!=-1){return dp[x][y];}
    int down=matrix[x][y]+minfallp(x+1,y,matrix,dp,n);
    int leftd=matrix[x][y]+minfallp(x+1,y-1,matrix,dp,n);
    int rightd=matrix[x][y]+minfallp(x+1,y+1,matrix,dp,n);
    return dp[x][y]=min(min(leftd,rightd),down);
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int minno=INT_MAX;
       vector<vector<int>> dp(n,vector<int>(n,-1));
       for(int j=0;j<n;j++){
        int x=minfallp(0,j,matrix,dp,n);
        minno=min(x,minno);
       }
       return minno;   
    }
};*/
// tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i+1][j];
                int leftd=matrix[i][j]+1e7;
                int rightd=matrix[i][j]+1e7;
                if(j>0){leftd=matrix[i][j]+dp[i+1][j-1];}
                if(j<n-1){rightd=matrix[i][j]+dp[i+1][j+1];}
                dp[i][j]=min(min(leftd,rightd),down);
            }
        }
        int minno=INT_MAX;
        for(int j=0;j<n;j++){
            minno=min(dp[0][j],minno);
        }
        return minno;
        
    }
};