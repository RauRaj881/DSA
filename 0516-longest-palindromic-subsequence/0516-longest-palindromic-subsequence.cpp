class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int nottake=max(dp[i-1][j],dp[i][j-1]);
                int take=0;
                if(s[i-1]==t[j-1]){
                    take=1+dp[i-1][j-1];
                }
                dp[i][j]=max(take,nottake);
            }
        }
        int j=n,i=n;
        string ans="";
        while(i>0&&j>0){
            if(s[i-1]==t[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        return ans.size();
    }
};