class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int mx=0;
            for(int sz=1;sz<=k;sz++){
                int j=i-sz+1;
                if(j>=0){
                    mx=max(mx,arr[j]);
                    int x=j>0?dp[j-1]:0;
                    dp[i]=max(dp[i],x+mx*sz);
                }
            }
        }
        return dp[n-1];
    }
};