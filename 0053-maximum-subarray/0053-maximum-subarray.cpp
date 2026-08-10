class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxno=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxno=max(sum,maxno);
            if(sum<0){sum=0;}
        }
        return maxno;
    }
};