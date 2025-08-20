//memoization
/*class Solution {
public:
bool SubSumUtil(int index,int target,vector<vector<int>> &dp,vector<int>&nums){
    if(target==0){return true;}
    if(index==0){return nums[index]==target;}
    if(dp[index][target]!=-1){return dp[index][target];}
    bool take =false;
    if(nums[index]<=target){
        take=SubSumUtil(index-1,target-nums[index],dp,nums);
    }
    bool nottake=SubSumUtil(index-1,target,dp,nums);
    return dp[index][target]=take||nottake;
}
    bool canPartition(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1){return false;}
        else {
            int target=sum/2;
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            return SubSumUtil(n-1,target,dp,nums);
        } 
    }
};*/
// tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1){return false;}
            int target=sum/2;
            vector<vector<bool>> dp(n,vector<bool>(target+1,0));
            for(int i=0;i<n;i++){
                dp[i][0]=1;
            }
            if(nums[0]<=target){
                dp[0][nums[0]]=1;
            }
            for(int i=1;i<n;i++){
                for(int sum=1;sum<=target;sum++){
                    bool nottake=dp[i-1][sum];//not pick se
                    bool take =0;
                    if(nums[i]<=sum){
                        take=dp[i-1][sum-nums[i]];//take se
                    }
                    dp[i][sum]=take||nottake;
                }
            }
            return dp[n-1][target];
    }
};