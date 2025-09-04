class Solution {
public:
int f(int i,int k,vector<int>& arr,vector<int> &dp,int n){
    if(i>=n){return 0;}
    if(dp[i]!=-1){return dp[i];}
    int maxsum=INT_MIN;
    int maxn=INT_MIN;
    for(int j=i;j<i+k;j++){
        if(j<=n-1){
        maxn=max(maxn,arr[j]);
        int sum=maxn*(j-i+1)+f(j+1,k,arr,dp,n);
        maxsum=max(sum,maxsum);
    }
    }
    return dp[i]=maxsum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,k,arr,dp,n);   
    }
};