class Solution {
public:
    void backtrack(vector<vector<int>> &v,  vector<int> &ans, vector<int> nums,int i,set<vector<int>> &mp){
        if(i==nums.size()){if(mp.find(ans)==mp.end()){v.push_back(ans);mp.insert(ans);}return;}
        ans.push_back(nums[i]);
        backtrack(v,ans,nums,i+1,mp);
        ans.pop_back();
        backtrack(v,ans,nums,i+1,mp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        set<vector<int>> mp;
        sort(nums.begin(),nums.end());
        backtrack(v,ans,nums,0,mp);
        return v;
    }
};