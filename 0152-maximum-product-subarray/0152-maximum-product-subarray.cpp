class Solution {
public:
    int maxProduct(vector<int>& nums){
        int crmn=1;
        int crmx=1;
        int ans=-1e6;
        for(int i=0;i<nums.size();i++){
            int omn=crmn;
            crmn=min({crmx*nums[i],crmn*nums[i],nums[i]});
            crmx=max({crmx*nums[i],omn*nums[i],nums[i]});
            ans=max(ans,crmx);
        }
        return ans;
    }
};