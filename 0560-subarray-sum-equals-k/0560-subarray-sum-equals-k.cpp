class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int presm=0;
        int ans=0;
        for(int i=0;i<n;i++){
            presm+=nums[i];
            ans+=mp[presm-k];
            mp[presm]++;
        }
        return ans;
    }
};