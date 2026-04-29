class Solution {
public:
int f(vector<int>& arr,int j,int i){
    int mx=0;
    for(int idx=j;idx<=i;idx++){
        mx=max(mx,arr[idx]);
    }
    return mx;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            for(int sz=1;sz<=k;sz++){
                int j=i-sz+1;
                if(j>=0){
                    int mx=f(arr,j,i);
                    int x=j>0?dp[j-1]:0;
                    dp[i]=max(dp[i],x+mx*sz);
                }
            }
        }
        return dp[n-1];
    }
};