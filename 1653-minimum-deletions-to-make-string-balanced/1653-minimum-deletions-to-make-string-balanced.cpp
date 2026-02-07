class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if(n==1){return 0;}
        vector<int> suf(n);
        suf[n-1]=(s[n-1]=='a'?1:0);
        for(int i=n-2;i>=0;i--){
            if(s[i]=='a'){suf[i]=suf[i+1]+1;}
            else{suf[i]=suf[i+1];}
        }
        int cnt=s[0]=='b'?1:0;
        int ans=suf[1];
        for(int i=1;i<n-1;i++){
            ans=min(ans,suf[i+1]+cnt);
            if(s[i]=='b'){cnt++;}
        }
        ans=min(ans,cnt);
        return ans;
    }
};