class Solution {
public:
    int maxPalindromes(string s, int k){
        int n=s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                }
            }
        }
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+k-1;j<n;j++){
                if(palin[i][j]){
                    dp[j]=max(dp[j],(i>0?dp[i-1]:0)+1);
                }
                if(j>0)dp[j]=max(dp[j],dp[j-1]);
            }
        }
        return dp[n-1];        
    }
};