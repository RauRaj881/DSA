class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
        if(n==1) return nums[0];
        
        int cs=0;
        int ts=INT_MIN;
        for(int s:nums){
            cs+=s;
            ts=max(ts,cs);
            if(cs<0){
                cs=0;
            }
            

        }
        return ts; 
    }
};