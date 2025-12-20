//memoization
/*class Solution {
public:
int LIS(int index,int prev,vector<int>& nums,vector<vector<int>> &dp,int n){
    if(index==n){return 0;}
    if(dp[index][prev+1]!=-1){return dp[index][prev+1];}
    int nottake=LIS(index+1,prev,nums,dp,n);
    int take=0;
    if(prev==-1||nums[index]>nums[prev]){
        take=1+LIS(index+1,index,nums,dp,n);
    }
    return dp[index][prev+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp,n);
    }
};*/
//tabulation
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<i;prev++){
                int nottake=dp[i+1][prev+1];
                int take=0;
                if(prev==-1||nums[i]>nums[prev]){
                   take=1+dp[i+1][i+1];
                }
               dp[i][prev+1]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[prev]+1,dp[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
//space optimization
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int> curr(n+1);
            for(int prev=-1;prev<i;prev++){
                int nottake=pre[prev+1];
             int take=0;
            if(prev==-1||nums[i]>nums[prev]){
            take=1+pre[i+1];
            }
          curr[prev+1]=max(take,nottake);
            }
            pre=curr;
        }
        return pre[0];
    }
};*/
// special solution(O(N^2))
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
        }
        int maxno=0;
        for(int i=0;i<n;i++){
            maxno=max(maxno,dp[i]);
        }
        return maxno;
    }
};*/
// using binary search (most optimized-O(nlogn));
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
    }
};*/