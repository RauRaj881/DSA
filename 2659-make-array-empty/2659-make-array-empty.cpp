class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        long long tot=n;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int prev=nums[i-1];
            if(mp[curr]<mp[prev]){tot+=n-i;}
        }
        return tot;
    }
};