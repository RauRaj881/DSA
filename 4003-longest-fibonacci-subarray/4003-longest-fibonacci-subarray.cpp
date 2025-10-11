class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=2;
        int curlength=2;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2]){curlength++;}
            else{mx=max(curlength,mx);curlength=2;}
        }
        mx=max(curlength,mx);
        return mx;
    }
};