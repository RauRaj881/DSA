class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        int mx=nums[0];
        int mn=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int cr=nums[i];
            int tp=max({cr,mx*cr,mn*cr});
            mn=min({cr,mx*cr,mn*cr});
            mx=tp;
            ans=max(ans,mx);
        }
        return ans;
    }
};