class Solution {
public:
vector<vector<int>> ans;
void f(int i,vector<int>& tp,vector<int>& nums){
    ans.push_back(tp);
    for(int idx=i;idx<nums.size();idx++){
        if(idx>i&&nums[idx]==nums[idx-1]){continue;}
        tp.push_back(nums[idx]);
        f(idx+1,tp,nums);
        tp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> tp;
        f(0,tp,nums);
        return ans;
    }
};