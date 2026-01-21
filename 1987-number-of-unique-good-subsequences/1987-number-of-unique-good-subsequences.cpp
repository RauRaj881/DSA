class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.length();
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        bool hasZero = false;

        for (int i = 1; i <= n; i++) {
            char c = binary[i - 1];
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];

            if (c == '1') {
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]+1) % mod;
            } else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
                hasZero = true;
            }
        }
        return (dp[n][0] + dp[n][1] + (hasZero ? 1 : 0)) % mod;
        
    }
};