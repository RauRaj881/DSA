class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(auto it:nums){tot+=it;}
        int sum=0,ans=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if((sum-(tot-sum))%2==0){ans++;}
        }
        return ans;
    }
};