class Solution {
public:
    void backtrack(vector<vector<int>>&v,vector<int>&ans,vector<int>& candidates,int target,int s,int i){
        if(i==candidates.size() || s>target){
            if(s==target){
                v.push_back(ans);
            }
            return;
        }
        ans.push_back(candidates[i]);
        s+=candidates[i];
        backtrack(v,ans,candidates,target,s,i);
        ans.pop_back();
        s-=candidates[i];
        backtrack(v,ans,candidates,target,s,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> v;
        vector<int> ans;
        backtrack(v,ans,candidates,target,0,0);
        return v;
    }                                  
};