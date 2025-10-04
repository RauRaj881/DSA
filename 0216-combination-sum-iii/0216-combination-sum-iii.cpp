class Solution {
public:
void f(int k, int n,vector<int> &temp,vector<vector<int>> &ans,int i){
    if(k<0){
        return;
    }
    if(k==0){
        if(n==0){ans.push_back(temp);}
        return;
    }
    for(int j=i;j<=9;j++){
        temp.push_back(j);
        f(k-1,n-j,temp,ans,j+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(k,n,temp,ans,1);
        return ans;
    }
};