class Solution {
public:
vector<vector<string>> ans;
bool ispalindrome(int i,int j,string s){
    while(i<=j){
        if(s[i]==s[j]){i++;j--;}
        else{return false;}
    }
    return true;
}
void f(int i,string s,vector<string>& tp){
    if(i==s.size()){ans.push_back(tp);return;}
    for(int j=i;j<s.size();j++){
        if(ispalindrome(i,j,s)){
            tp.push_back(s.substr(i,j-i+1));
            f(j+1,s,tp);
            tp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s){
        vector<string> tp;
        f(0,s,tp);
        return ans;
    }
};