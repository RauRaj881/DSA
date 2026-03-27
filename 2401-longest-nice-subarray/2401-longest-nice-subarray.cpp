class Solution {
public:
    int longestNiceSubarray(vector<int>& nums){
        int n=nums.size();
        int l=0;
        int nm=0;
        int ans=0;
        for(int r=0;r<n;r++){
            while((nm&nums[r])!=0){
                nm^=nums[l];
                l++;
            }
            nm|=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};