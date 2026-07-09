class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fn(nums,goal)-fn(nums,goal-1);
    }
    int fn(vector<int>& nums, int goal){
        if(goal<0){return 0;}
        int sum=0,left=0,right=0,h=0;
        while(right!=nums.size()){
        sum+=nums[right];
        while(sum>goal){
            sum=sum-nums[left];
            left++;
        }
        h+=right+1-left;
        right++;
        }
        return h;
    }
};