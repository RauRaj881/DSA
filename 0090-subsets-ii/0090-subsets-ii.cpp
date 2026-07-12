class Solution {
public:
vector<vector<int>> ans;
void f(int idx,vector<int>& nums,vector<int>&path){
    ans.push_back(path);
    for(int i=idx;i<nums.size();i++){
        if(i>idx&&nums[i]==nums[i-1]){continue;}
        path.push_back(nums[i]);
        f(i+1,nums,path);
        path.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> path;
        f(0,nums,path);
        return ans;
    }
};