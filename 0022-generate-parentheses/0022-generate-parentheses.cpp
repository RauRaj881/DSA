class Solution {
public:
vector<string> ans;
void f(int open,int close,string tp,int n){
    if(tp.size()==2*n){ans.push_back(tp);return;}
    if(open<n){
        f(open+1,close,tp+'(',n);
    }
    if(close<open){
        f(open,close+1,tp+')',n);
    }
}
    vector<string> generateParenthesis(int n){
        string tp="";
        f(0,0,tp,n);
        return ans;
    }
};