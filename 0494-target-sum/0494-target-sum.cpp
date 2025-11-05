//memoization
/*class Solution {
public:
int tarsum(int index, vector<vector<int>> &dp,vector<int>& nums,int target){
    if(index==0){
        if(target==0&&nums[0]==0){return 2;}
        else if(target==0||nums[0]==target){return 1;}
        else{return 0;}
    }
    if(dp[index][target]!=-1){return dp[index][target];}
    int take=0;
    if(nums[index]<=target){
     take=tarsum(index-1,dp,nums,target-nums[index]);
    }
    int nottake=tarsum(index-1,dp,nums,target);
    return dp[index][target]=take+nottake;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        int newtar=(totsum+target)/2;
        if ((totsum + target) % 2 != 0 || abs(target) > totsum) return 0;
        vector<vector<int>> dp(n,vector<int>(newtar+1,-1));
        return tarsum(n-1,dp,nums,newtar);
    }
};*/
//tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        int newtar=(totsum+target)/2;
        if ((totsum - target) % 2 != 0 || abs(target) > totsum) return 0;
        vector<vector<int>> dp(n,vector<int>(newtar+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=newtar){dp[0][nums[0]]++;}

        for(int i=1;i<n;i++){
            for(int sum=0;sum<=newtar;sum++){
                int nottake=dp[i-1][sum];
                int take=0;
                if(nums[i]<=sum){
                    take=dp[i-1][sum-nums[i]];
                }
                dp[i][sum]=take+nottake;
            }
        }
        return dp[n-1][newtar];
    }
};
//space optimization
/*class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        int newtar=(totsum+target)/2;
        if ((totsum + target) % 2 != 0 || abs(target) > totsum) return 0;
        vector<int> prev(newtar+1,0);
        if(nums[0]==0){
            prev[0]=2;//pick+notpick
        }
        else{prev[0]=1;}//notpick
        if(nums[0]!=0&&nums[0]<=newtar){
            prev[nums[0]]=1;//pick
        }
        for(int i=1;i<n;i++){
            vector<int> curr(newtar+1);
            for(int sum=0;sum<=newtar;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[i]<=sum){
                    take=prev[sum-nums[i]];
                }
                curr[sum]=take+nottake;
            }
            prev=curr;
        }
        return prev[newtar];
    }
};*/