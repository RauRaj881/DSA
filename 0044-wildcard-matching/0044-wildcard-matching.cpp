class Solution {
public:
int n,m;
vector<vector<int>>dp;
    bool isMatch(string s, string p) {
        n=s.size(), m=p.size();
        dp.resize(n,vector<int>(m,-1));
       return  solve(s,p,n-1,m-1);
    }
bool check(string &str){
    for(int i=0; i<str.size(); i++){
        if(str[i]!='*') return false;
    }
    return true;
}
    bool solve(string &s, string&p, int i, int j){ 

        if(i<0 && j<0) return true;

        if(i<0 && j>=0) {
            string str=p.substr(0,j+1);
            if(check(str)) return true;
            return false;
        }
        if(i>=0 && j<0) return false;
        // if(i<0 || j<0) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]= solve(s,p,i-1,j-1);
        }
        else if(p[j]!='*' && s[i]!=p[j]) return false;

        // else{
            return dp[i][j]= solve(s,p,i,j-1) || solve(s,p,i-1,j);
        // }
    }
};