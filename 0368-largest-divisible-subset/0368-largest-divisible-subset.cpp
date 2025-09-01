class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int maxno=0,lastindex;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxno){
                maxno=dp[i];
                lastindex=i;
            }
        }
        vector<int> ans;
        while(hash[lastindex]!=lastindex){
            ans.push_back(nums[lastindex]);
            lastindex=hash[lastindex];
        }
        ans.push_back(nums[lastindex]);
        return ans;
    }
};