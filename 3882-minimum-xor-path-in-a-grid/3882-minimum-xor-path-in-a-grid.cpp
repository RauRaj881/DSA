class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
            dp[0][0][grid[0][0]]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<1024;k++){
                    if(i==0&&j==0&&k==grid[0][0]){dp[i][j][k]=true;continue;}
                    if(j>0){
                        if(dp[i][j-1][k^grid[i][j]]){
                            dp[i][j][k]=true;
                        }
                    }
                    if(i>0){
                        if(dp[i-1][j][k^grid[i][j]]){
                            dp[i][j][k]=true;
                        }
                    }
                }
            }
        }
        for(int i=0;i<1024;i++){
            if(dp[n-1][m-1][i]){return i;}
        }
        return 12345;
        
    }
};