class Solution {
public:
    void backtrack(vector<vector<int>>& v, vector<int>& ans,
vector<int>& c, int target, int sum, int idx){
    if(sum==target){v.push_back(ans);return;}
    for(int i=idx;i<c.size();i++){
        if(i>idx&&c[i]==c[i-1]){continue;}
        if(sum+c[i]>target){break;}
        ans.push_back(c[i]);
        backtrack(v,ans,c,target,sum+c[i],i+1);
        ans.pop_back();
    }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<vector<int>> v;
        vector<int> ans;
        backtrack(v, ans, c, target, 0, 0);
        return v;
    }
};