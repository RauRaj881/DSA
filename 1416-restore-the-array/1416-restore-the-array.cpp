class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1);
        dp[n] = 1; 
        for (int i=n-1;i>=0;--i) {
        if (s[i]=='0')
            continue;
           for (long sz=1,m=0;i+sz<=n;++sz) {
               m=m*10+s[i+sz-1]-'0';
               if (m > k)
                   break;
                dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
            }
        }
    return dp[0];
}
};