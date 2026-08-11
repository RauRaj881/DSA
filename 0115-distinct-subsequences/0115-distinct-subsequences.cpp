#define ll long long
class Solution {
public:
    int numDistinct(string s, string t){
        int n=s.size();
        int m=t.size();
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        for(int i=0;i<=n;i++){dp[i][0]=1;}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int tk=0;
                if(s[i-1]==t[j-1]){
                    tk=dp[i-1][j-1];
                }
                dp[i][j]=tk+dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};