class Solution {
public:
int recur(int ind,vector<int> &dp,vector<int>& nums){
    if(ind==0){return nums[0];}
    else if(ind<0){return 0;}
    if(dp[ind]!=-1){return dp[ind];}
    int pick=nums[ind]+recur(ind-2,dp,nums);
    int notpick=recur(ind-1,dp,nums);
    return dp[ind]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(n-1,dp,nums);

    }
};