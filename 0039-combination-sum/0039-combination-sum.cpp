class Solution {
public:
vector<vector<int>> ans;
void f(int i,int sm,int tar,vector<int>& c,vector<int>& tp){
    if(i==c.size()||sm>tar){if(sm==tar){ans.push_back(tp);}return;}
    tp.push_back(c[i]);
    f(i,sm+c[i],tar,c,tp);
    tp.pop_back();
    f(i+1,sm,tar,c,tp);
}
    vector<vector<int>> combinationSum(vector<int>& c,int tar){
        int n=c.size();
        vector<int> tp;
        f(0,0,tar,c,tp);
        return ans;
    }
};