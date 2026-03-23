class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int mod=1e9+7;
        vector<vector<long long>> dp1(m,vector<long long>(n));
        vector<vector<long long>> dp2(m,vector<long long>(n));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                long long val=grid[i][j];
                if(i==m-1&&j==n-1){dp1[i][j]=val;}
                else if(i==m-1){dp1[i][j]=max(dp1[i][j+1]*val,dp2[i][j+1]*val);}
                else if(j==n-1){dp1[i][j]=max(dp1[i+1][j]*val,dp2[i+1][j]*val);}
                else{long long a=max(dp1[i+1][j]*val,dp1[i][j+1]*val);
                long long b=max(dp2[i+1][j]*val,dp2[i][j+1]*val);
                dp1[i][j]=max(a,b);}


                if(i==m-1&&j==n-1){dp2[i][j]=val;}
                else if(i==m-1){dp2[i][j]=min(dp2[i][j+1]*val,dp1[i][j+1]*val);}
                else if(j==n-1){dp2[i][j]=min(dp1[i+1][j]*val,dp2[i+1][j]*val);}
                else{long long a=min(dp1[i+1][j]*val,dp1[i][j+1]*val);
                long long b=min(dp2[i+1][j]*val,dp2[i][j+1]*val);
                dp2[i][j]=min(a,b);}      
            }
        }
        if(dp1[0][0]<0){return -1;}
        return dp1[0][0]%mod;
    }
};