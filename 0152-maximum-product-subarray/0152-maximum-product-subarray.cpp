class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        int mx=nums[0],mn=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            ans=max({ans,mx*nums[i],mn*nums[i],nums[i]});
            int ori=mx;
            mx=max({mn*nums[i],mx*nums[i],nums[i]});
            mn=min({mn*nums[i],ori*nums[i],nums[i]});
        }
        return ans;
    }
};