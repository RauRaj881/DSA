class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=1;i<=k;i++){
            if(i<=target)dp[1][i]=1;
        }
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            for(int g=1;g<=target;g++){
                for(int x=1;x<=k;x++){
                    if(g-x>=0)dp[i][g]=(dp[i][g]+dp[i-1][g-x])%(mod);
                }
            }
        }
        return dp[n][target];

    }
};