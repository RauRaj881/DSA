class Solution {
public:
    bool rotateString(string s, string g){
        if(s.size()!=g.size()){return false;}
        int n=s.size();
        for(int st=0;st<n;st++){
            int i=st,j=0;
            int cnt=0;
            while(cnt!=n){
                if(s[i]!=g[j]){break;}
                else{i=(i+1)%n;j++;cnt++;}
            }
            if(cnt==n){return true;}
        }
        return false;
    }
};