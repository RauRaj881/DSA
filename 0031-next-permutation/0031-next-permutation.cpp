class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int n=nums.size();
        int idx=n;
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){idx=i-1;break;}
        }
        if(idx==n){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>idx;i--){
            if(nums[i]>nums[idx]){swap(nums[idx],nums[i]);break;}
        }
        sort(nums.begin()+idx+1,nums.end());      
    }
};