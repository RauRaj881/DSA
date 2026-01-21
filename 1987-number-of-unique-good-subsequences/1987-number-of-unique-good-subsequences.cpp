class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        bool pos=false;
        if(s[0]=='1'){dp[0][1]=1;}
        else{pos=true;}
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                dp[i][1]=(dp[i-1][1]+dp[i-1][0]+1)%(mod);
                dp[i][0]=(dp[i-1][0])%mod;
            }
            else{
                pos=true;
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])%(mod);
                dp[i][1]=(dp[i-1][1])%mod;
            }
        }
        return (dp[n-1][0]+dp[n-1][1]+pos)%mod;
    }
};