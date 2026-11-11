class Solution {
public:
vector<vector<int>> ans;
void solve(int idx,int n,vector<int>& nums,vector<int> temp){
    ans.push_back(temp);
    for(int i=idx;i<n;i++){
        if(i>idx&&nums[i]==nums[i-1]){continue;}
        temp.push_back(nums[i]);
        solve(i+1,n,nums,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,n,nums,temp);
        return ans;
    }
};