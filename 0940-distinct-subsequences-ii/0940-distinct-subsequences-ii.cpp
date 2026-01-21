class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(26,0));
        int curr=s[0]-'a';
        dp[0][curr]=1;
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            curr=s[i]-'a';
            for(int j=0;j<26;j++){
                if(j!=curr){
                    dp[i][j]=dp[i-1][j]%mod;
                }
                else{
                    for(int k=0;k<26;k++){
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%(mod);
                    }
                    dp[i][j]+=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};