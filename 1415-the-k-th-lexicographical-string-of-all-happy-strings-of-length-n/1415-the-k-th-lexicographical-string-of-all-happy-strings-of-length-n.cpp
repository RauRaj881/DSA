class Solution {
public:
void f(string s,int n,vector<string> &v){
    if(s.size()==n){
        v.push_back(s);
        return;
    }
    for(char ch='a';ch<='c';ch++){
        if(s.size()>0&&s.back()==ch){continue;}
        f(s+ch,n,v);
    }
}
    string getHappyString(int n, int k) {
        vector<string> v;
        f("",n,v);
        if(v.size()<k){return "";}
        return v[k-1];
    }
};