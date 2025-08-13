// memoviazation
/*class Solution {
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
};*/
//tabulation
/*class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            int take=nums[i];
            if(i>1){take+=dp[i-2];}
            int nottake=0;
            if(i>0){
            nottake+=dp[i-1];
            }
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};*/
// space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
int prev2=0;
int curr;
for(int i=0;i<n;i++){
    int take=nums[i]+prev2;
    int nottake=prev;
    curr=max(take,nottake);
    prev2=prev;
    prev=curr;
}
return curr;
    }
};