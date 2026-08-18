class Solution {
public:
    int longestPalindromeSubseq(string s){
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //dp[i][j]=length of longest common subsequence in string s[0...i] and string t[0...j];
        //dp[n-1][n-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int tk=0;
                if(s[i-1]==t[j-1]){tk=dp[i-1][j-1]+1;}
                int nt=max(dp[i][j-1],dp[i-1][j]);
                dp[i][j]=max(tk,nt);
            }
        }
        return dp[n][n];
    }
};