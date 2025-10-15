class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        vector<int> presum(n);
        presum[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                ans=max(ans,cnt/2);
                }
                else{cnt=1;}
                if((i-cnt)>=0&&presum[i-cnt]>=cnt){
                    ans=max(ans,cnt);
                }
                presum[i]=cnt;
        }
        return ans;
    }
};