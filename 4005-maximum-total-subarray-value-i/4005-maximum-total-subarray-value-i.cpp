class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn=INT_MAX;
        int mx=-1;
        for(long long i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        long long ans=(long long)(mx-mn)*k;
        return ans;
    }
};