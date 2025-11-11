class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=0;i<=sz;i++){
            dp[i][0][0]=0;
        }
        for(int i=1;i<=sz;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    string curr=strs[i-1];
                    int cnt1=0,cnt0=0;
                    for(auto it:curr){if(it=='1'){cnt1++;}else{cnt0++;}}
                    int nottake=dp[i-1][j][k];
                    int take=0;
                    if(cnt0<=j&&cnt1<=k){
                        take=1+dp[i-1][j-cnt0][k-cnt1];
                    }
                    dp[i][j][k]=max(take,nottake);
                }
            }
        }
        return dp[sz][m][n];
    }
};