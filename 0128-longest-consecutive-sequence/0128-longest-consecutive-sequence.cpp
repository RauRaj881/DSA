class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
            int lt=mp.count(nums[i]-1)?mp[nums[i]-1]:0;
            int rt=mp.count(nums[i]+1)?mp[nums[i]+1]:0;
            mp[nums[i]]=lt+rt+1;
            mp[nums[i]-lt]=mp[nums[i]];
            mp[nums[i]+rt]=mp[nums[i]];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mp[nums[i]]);
        }
        return ans;
        
    }
};