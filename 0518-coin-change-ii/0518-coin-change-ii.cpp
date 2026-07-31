#define ull unsigned long long
class Solution {
public:
    int change(int amt,vector<int>& c){
        int n=c.size();
        vector<vector<ull>> dp(n,vector<ull>(amt+1,0));
        dp[0][0]=1;
        for(int i=c[0];i<=amt;i+=c[0]){
            dp[0][i]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                ull nt=dp[i-1][j];
                ull t=0;
                if(c[i]<=j){t=dp[i][j-c[i]];}
                dp[i][j]=t+nt;
            }
        }
        //if(dp[n-1][amt]==1e9){return -1;}
        return dp[n-1][amt];
    }
};