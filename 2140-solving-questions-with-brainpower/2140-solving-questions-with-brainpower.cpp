class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long> dp(n,0);
        dp[n-1]=q[n-1][0];
        for(int i=n-2;i>=0;i--){
            int d=q[i][1];
            dp[i]=max(dp[i+1],q[i][0]+(i+d+1<n?dp[i+d+1]:0));
        }
        return dp[0];
    }
};