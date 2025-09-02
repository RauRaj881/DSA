class Solution {
public:
bool check(string &s1,string &s2,int i1,int i2){
   if (s1.size()!=s2.size()+1) return false;
    while(i1!=s1.size()&&i2!=s2.size()){
        if(s1[i1]==s2[i2]){
            i1++;i2++;
        }
        else if(s1[i1]!=s2[i2]) {
                i1++;
                if(abs(i1-i2)>1){return false;}
        }

    }
    return true;
}
  static bool comp(string&str1,string&str2){
    return str1.size()<str2.size();
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxno=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev],0,0) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxno){
                maxno=dp[i];
            }
        }
        return maxno;
    }
};