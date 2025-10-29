/*class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev=0;
        int n=nums.size();
        int curr;
        if(n==1){return nums[0];}
        for(int i=0;i<n-1;i++){
            int pick=nums[i];
            if(i>1){pick+=prev2;}
            int notpick=0;
            if(i>0){notpick+=prev;}
            curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        int pre2=0;
        int pre=0;
        int curr2;
        for(int i=1;i<n;i++){
            int pick2=nums[i];
            if(i>2){pick2+=pre2;}
            int notpick2=0;
            if(i>1){notpick2+=pre;}
            curr2=max(pick2,notpick2);
            pre2=pre;
            pre=curr2;
        }
        return max(curr,curr2);
    }
};*/
class Solution {
public:
int solve(vector<int> &nums){
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        vector<int> case1(nums.begin(),nums.end()-1);
        vector<int> case2(nums.begin()+1,nums.end());
        return max(solve(case1),solve(case2));
    }
};