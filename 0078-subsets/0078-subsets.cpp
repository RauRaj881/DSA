class Solution {
public:
    void backtrack(vector<vector<int>> &v,  vector<int> &ans, vector<int> nums,int i){
        if(i==nums.size()){v.push_back(ans);return;}
        ans.push_back(nums[i]);
        backtrack(v,ans,nums,i+1);
        ans.pop_back();
        backtrack(v,ans,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        backtrack(v,ans,nums,0);
        return v;
    }
};