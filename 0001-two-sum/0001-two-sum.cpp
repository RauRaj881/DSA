/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target) {v.push_back(i); v.push_back(j);}
            }
        }
        return v;
    }
};*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        mp[nums[0]]=0;
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(mp.count(target-nums[i])){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};