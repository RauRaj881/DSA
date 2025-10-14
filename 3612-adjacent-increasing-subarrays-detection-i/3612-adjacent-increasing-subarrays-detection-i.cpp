class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=1;
        vector<int> presum(n);
        presum[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                }
                else{cnt=1;}
                if(cnt>=k&&(i-k)>=0&&presum[i-k]>=k){
                    return true;
                }
                presum[i]=cnt;
        }
        return false;
    }
};