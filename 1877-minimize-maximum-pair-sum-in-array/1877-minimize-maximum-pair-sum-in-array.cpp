class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            int n=nums.size();
            int i=0,j=n-1;
        int mx=0;
            while(i<j){
                mx=max(mx,nums[j]+nums[i]);i++;j--;
            }
            return mx;
        
    }
};