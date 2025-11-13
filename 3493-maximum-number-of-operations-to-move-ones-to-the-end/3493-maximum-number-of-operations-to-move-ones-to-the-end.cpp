class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int cnt1=0,cnt0=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){cnt1++;cnt0=0;}
            else{cnt0++;}
            if(cnt0==1){ans+=cnt1;}
        }
        return ans;
    }
};