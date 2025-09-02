class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
         vector<int> cnt(n,1);
        int maxno=0;
        if(n==1){return 1;}
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]&&dp[i]<1+dp[prev]){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev]&&dp[i]==1+dp[prev]){
                    dp[i]=dp[prev]+1;
                    cnt[i]+=cnt[prev];
                }
                maxno=max(dp[i],maxno);
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxno){
                x+=cnt[i];
            }
        }
        return x;
    }
};