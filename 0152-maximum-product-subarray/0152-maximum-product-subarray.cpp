class Solution {
public:
    int maxProduct(vector<int>& nums){
        int mn=1;
        int mx=1;
        int ans=-1e6;
        for(int i=0;i<nums.size();i++){
            int omn=mn;
            mn=min({mx*nums[i],mn*nums[i],nums[i]});
            mx=max({mx*nums[i],omn*nums[i],nums[i]});
            ans=max(ans,mx);
        }
        return ans;
    }
};