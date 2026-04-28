class Solution {
public:
vector<vector<int>> ans;
void f(int i,vector<int>& cd,vector<int>& path,int tar,int sm){
    if(i==cd.size()){
        if(sm==tar){ans.push_back(path);}
        return;
    }
    //path.push_back(cd[i]);
    //sm+=cd[i];
    f(i+1,cd,path,tar,sm);
    if(cd[i]+sm<=tar){
        path.push_back(cd[i]);
    f(i,cd,path,tar,sm+cd[i]);
    path.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& cd, int tar){
        int n=cd.size();
        vector<int> path;
        f(0,cd,path,tar,0);
        return ans;
    }
};