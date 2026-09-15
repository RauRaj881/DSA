class Solution {
public:
vector<vector<int>> ans;
void f(int i,int n,vector<int>& c,int tar,vector<int>& tp,int sm){
    if(sm==tar){ans.push_back(tp);return;}
    if(sm>tar){return;}
    for(int idx=i;idx<n;idx++){
        if(idx>i&&c[idx]==c[idx-1]){continue;}
        tp.push_back(c[idx]);
        f(idx+1,n,c,tar,tp,sm+c[idx]);
        tp.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& c,int tar){
        sort(c.begin(),c.end());
        int n=c.size();
        vector<int> tp;
        f(0,n,c,tar,tp,0);
        return ans;
    }
};