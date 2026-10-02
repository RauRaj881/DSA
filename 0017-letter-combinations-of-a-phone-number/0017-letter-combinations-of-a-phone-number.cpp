class Solution {
public:
vector<string> ans;
void f(int idx,string& d,string& tp,vector<string>& v){
    if(idx==d.size()){ans.push_back(tp);return;}
    int nm=d[idx]-'0';
    for(int j=0;j<v[nm].size();j++){
        tp+=v[nm][j];
        f(idx+1,d,tp,v);
        tp.pop_back();
    }
}
    vector<string> letterCombinations(string d){
        int n=d.size();
        vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string tp="";
        f(0,d,tp,v);
        return ans;
    }
};