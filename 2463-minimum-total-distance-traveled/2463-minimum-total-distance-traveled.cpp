typedef long long ll;
class Solution {
public:
    long long minimumTotalDistance(vector<int>& rob,vector<vector<int>>& fact){
        sort(rob.begin(),rob.end());
        vector<int> slots;
        for (auto &f : fact) {
            for (int i = 0; i < f[1]; i++) {
                slots.push_back(f[0]);
            }
        }
        sort(slots.begin(), slots.end());
        int n=rob.size();
        int m=slots.size();
        vector<vector<ll>> dp(n,vector<ll>(m,1e12));
        for(int i=0;i<m;i++){
            dp[0][i]=min((ll)(i>0?dp[0][i-1]:1e12),(ll)abs(slots[i]-rob[0]));
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+(ll)abs(rob[i]-slots[j]));
            }
        }
        return dp[n-1][m-1];
    }
};