class Solution {
public:
    bool canJump(vector<int>& nums){
        int n=nums.size();
        int mx=0;
        for(int i=0;i<nums.size()-1;i++){
            if(mx>=i)mx=max(mx,i+nums[i]);
        }
        return mx>=n-1;
    }
};