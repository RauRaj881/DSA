class Solution {
public:
vector<vector<string>> ans;
void f(int i,int n,string s,vector<string> &tp){
    if(i==n){
        ans.push_back(tp);return;
    }
    for(int j=i;j<n;j++){
        if(ispalindrome(s,i,j)){
            tp.push_back(s.substr(i,j-i+1));
            f(j+1,n,s,tp);
            tp.pop_back();
        }
    }
}
bool ispalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]==s[j]){i++;j--;}
        else{return false;}
    }
    return true;
}
    vector<vector<string>> partition(string s){
        int n=s.size();
        vector<string> tp;
        f(0,n,s,tp);
        return ans;
        
    }
};