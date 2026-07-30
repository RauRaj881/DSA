class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri){
        int m=tri.size();
        int n=tri[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=tri[0][0];
        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                int up=INT_MAX;
                int lt=INT_MAX;
                if(j>0){lt=dp[i-1][j-1];}
                if(j<i){up=dp[i-1][j];}
                dp[i][j]=tri[i][j]+min(lt,up);
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<=m-1;j++){
            ans=min(ans,dp[m-1][j]);
        }
        return ans;
    }
};