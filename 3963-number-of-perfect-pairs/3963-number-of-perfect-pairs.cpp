class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            auto it=upper_bound(nums.begin(),nums.end(),2*nums[i]);//upper bound gives iterator not an index .for index substract nums.begin() from it.
            long long j=it-nums.begin();
            ans+=j-i-1;
        }
        return ans;
    }
};