class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int gl){
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int cr=0;
        for(int i=0;i<nums.size();i++){
            cr+=nums[i];
            if(mp.count(cr-gl)){ans+=mp[cr-gl];}
            mp[cr]++;
        }
        return ans;
    }
};