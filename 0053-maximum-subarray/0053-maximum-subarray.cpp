class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int cr=-1e9;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            cr=max(nums[i],nums[i]+cr);
            ans=max(ans,cr);
        }
        return ans;
    }
};