class Solution {
public:
vector<string> ans;
void f(int i,int n,string tp){
    if(i==n){ans.push_back(tp);return;}
    if(tp.empty()||tp.back()=='1'){
        f(i+1,n,tp+'0');
        f(i+1,n,tp+'1');
    }
    else{
        f(i+1,n,tp+'1');
    }
}
    vector<string> validStrings(int n){
        string tp="";
        f(0,n,tp);
        return ans;
    }
};