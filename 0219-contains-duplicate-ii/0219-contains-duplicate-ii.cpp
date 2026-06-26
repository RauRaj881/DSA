class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<=k;i++){
            if(i<n)mp[nums[i]]++;
        }
        if(k>=n){return mp.size()!=n;}
        if(mp.size()!=k+1){return true;}
        for(int i=k+1;i<n;i++){
            mp[nums[i-k-1]]--;
            if(mp[nums[i-k-1]]==0){mp.erase(nums[i-k-1]);}
            mp[nums[i]]++;
            if(mp.size()!=k+1){return true;}
        }
        return false;
    }
};