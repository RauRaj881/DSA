class Solution {
public:
int f(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp=grid;
    int cnt=0;
    for(int i=m-1;i>=0;i--){
        for(int j=1;j<n-1;j++){
            if(i==m-1){dp[i][j]=grid[i][j];}
            else{
                if(grid[i][j]==1){
                    dp[i][j]=min({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]})+1;
                    cnt+=dp[i][j]-1;
                }
            }
        }
    }
    return cnt;
}
    int countPyramids(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        ans+=f(grid);
        reverse(grid.begin(),grid.end());
        ans+=f(grid);
        return ans;
    }
};