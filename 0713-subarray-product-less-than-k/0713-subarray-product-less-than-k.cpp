class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        int n=nums.size();
        int cr=1;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            cr*=nums[r];
            while(cr>=k&&l<=r){
                cr/=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
        
    }
};