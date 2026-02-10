class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> nw;
        nw.push_back(1);
        for(auto it:nums){
            nw.push_back(it);
        }
        nw.push_back(1);
        int n=nw.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                for(int k=i+1;k<j;k++){
                    int curr=nw[k]*nw[i]*nw[j];
                    int tot=curr+dp[i][k]+dp[k][j];
                    dp[i][j]=max(dp[i][j],tot);
                }
            }
        }
        return dp[0][n-1];
    }
};