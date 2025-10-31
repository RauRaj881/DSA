class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){v.push_back(nums[i]);}
        }
        return v;
    }
};