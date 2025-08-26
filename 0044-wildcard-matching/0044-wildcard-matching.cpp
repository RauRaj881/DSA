class Solution {
public:
bool wildcard(int index1,int index2,vector<vector<int>> &dp,string &s, string &p){
    if(index1<0&&index2<0){return true;}
    else if(index1>=0&&index2<0){return false;}
    else if(index1<0&&index2>=0){
        for(int i=0;i<=index2;i++){
            if(p[i]!='*'){return false;}
        }
        return true;
    }
    if(dp[index1][index2]!=-1){return dp[index1][index2];}
    if(s[index1]==p[index2]||p[index2]=='?'){
        return dp[index1][index2]=wildcard(index1-1,index2-1,dp,s,p);
    }
    else if(p[index2]=='*'){
        return dp[index1][index2]=wildcard(index1-1,index2,dp,s,p)||wildcard(index1,index2-1,dp,s,p);
    }
    return dp[index1][index2]=false;
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcard(n-1,m-1,dp,s,p);
    }
};