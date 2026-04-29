class Solution {
public:
    void backtrack(vector<vector<int>>&v,vector<int>&ans,vector<int>& c,int target,int s,int i){
        if(i==c.size() || s>target){
            if(s==target){
                v.push_back(ans);
            }
            return;
        }
        ans.push_back(c[i]);
        //s+=c[i];
        backtrack(v,ans,c,target,s+c[i],i);
        ans.pop_back();
        //s-=c[i];
        backtrack(v,ans,c,target,s,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>> v;
        vector<int> ans;
        backtrack(v,ans,c,target,0,0);
        return v;
    }                                  
};