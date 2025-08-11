class Solution {
public:
void palinpar(int ind,string s,vector<vector<string>> &res,vector<string> &ans,int n){
    if(ind==n){
        res.push_back(ans);
        return;
    }
    for(int i=ind;i<n;i++){
        if(ispalindrome(s,ind,i)){
            ans.push_back(s.substr(ind,i-ind+1));
            palinpar(i+1,s,res,ans,n);
            ans.pop_back();
        }
    }
}
bool ispalindrome(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;end--;
    }
    return true;
}

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> res;
        vector<string> ans;
        palinpar(0,s,res,ans,n);
        return res;
    }
};