class Solution {
public:
    int minCut(string s){
        int n=s.size();
        vector<int> dp(n,n+1);
        vector<vector<bool>> palin(n,vector<bool>(n,false));
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j]&&(i-j<=2||palin[j+1][i-1])){
                    palin[j][i]=true;
                    dp[i]=min(dp[i],(j==0?1:dp[j-1]+1));
                }
            }
        }
        return dp[n-1]-1;
    }
};