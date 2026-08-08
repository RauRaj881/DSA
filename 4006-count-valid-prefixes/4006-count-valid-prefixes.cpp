class Solution {
public:
    int countValidPrefixes(string s){
        int cnt0=0,cnt1=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){cnt1++;}
            else{cnt0++;}
            if(abs(cnt0-cnt1)<=1){ans++;}
        }
        return ans;
    }
};