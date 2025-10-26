class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> presum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            presum[i]=sum;
        }
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=((presum[i]%k)+k)%k;
            if(mp.count(x)){
                ans+=mp[x];
            }
            mp[x]++;
        }
        return ans;
    }
};