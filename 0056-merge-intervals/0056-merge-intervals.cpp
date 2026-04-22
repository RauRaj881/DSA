class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv){
        int n=itv.size();
        sort(itv.begin(),itv.end());
        vector<vector<int>> ans;
        int a=itv[0][0];
        int mx=itv[0][1];
        for(int i=0;i<n;i++){
            if(itv[i][0]<=mx){
                mx=max(itv[i][1],mx);
            }
            else{ans.push_back({a,mx});a=itv[i][0];mx=itv[i][1];}
        }
        ans.push_back({a,mx});
        return ans;
    }
};