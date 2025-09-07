class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        sort(s.begin(),s.end());
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1] &&s[i]!='a'){
                cnt+=(s[i+1]-'a')-(s[i]-'a');
            }
        }
        if(s[n-1]!='a')cnt+=('z'-'a')-(s[n-1]-'a')+1;
        return cnt;
    }
};