class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k){
        int n=nums.size();
        long long ans=0;
        long long cr=0;
        int l=0;
        for(int r=0;r<n;r++){
            cr+=nums[r];
            int len=(r-l+1);
            while(cr*len>=k&&l<=r){
                cr-=nums[l];
                len--;
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};