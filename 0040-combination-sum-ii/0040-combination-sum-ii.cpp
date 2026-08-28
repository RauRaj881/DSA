class Solution {
public:
vector<vector<int>> ans;
void f(int i,int sm,vector<int>& c, int tar,vector<int>& tp){
    if(sm==tar){ans.push_back(tp);return;}
    if(sm>tar){return;}
    for(int idx=i;idx<c.size();idx++){
        if(idx>i&&c[idx]==c[idx-1]){continue;}
        tp.push_back(c[idx]);
        f(idx+1,sm+c[idx],c,tar,tp);
        tp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& c, int tar){
        sort(c.begin(),c.end());
        vector<int> tp;
        f(0,0,c,tar,tp);
        return ans;
    }
};