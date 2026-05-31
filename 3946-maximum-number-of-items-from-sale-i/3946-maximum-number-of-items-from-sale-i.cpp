class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& itms,int bud){
        int n=itms.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i&&itms[j][0]%itms[i][0]==0){v[i]++;}
            }
        }
        vector<vector<int>> dp(n,vector<int>(bud+1));
        int price0 = itms[0][1];
        for (int b = 0; b <= bud; b++) {
            if (b >= price0) {
                dp[0][b] =v[0] + (b)/ price0;
            }
        }
        for (int i = 1; i < n; i++) {
            int price = itms[i][1];
            for (int b = 0; b <= bud; b++) {
                dp[i][b] = dp[i-1][b];
                
                if (b >= price){
                    dp[i][b] = max(dp[i][b], dp[i-1][b - price] + 1+v[i]);
                    dp[i][b] = max(dp[i][b], dp[i][b - price] + 1);
                }
            }
        }
        return dp[n-1][bud];
    }
};