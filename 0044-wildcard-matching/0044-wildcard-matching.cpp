//memoization
/*class Solution {
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
};*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        int starIdx = -1, match = 0;
        while (i < n) {
            if (j < m && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            } 
            else if (j < m && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            } 
            else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            } 
            else {
                return false;
            }
        }
        while (j < m && p[j] == '*') j++;

        return j == m;
    }
};
