/*class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i][1]=max(dp[i][1],dp[j][0]+1);
                }
                else if(nums[i]<nums[j]){
                    dp[i][0]=max(dp[i][0],dp[j][1]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int up=1,down=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){up=down+1;}
            else if(nums[i]<nums[i-1]){down=up+1;}
        }
        return max(up,down);
    }
};