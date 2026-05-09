class Solution {
public:
    int minFlips(string s){
        int n=s.size();
        int cnt1=0,cnt0=0;
        for(auto it:s){
            if(it=='0'){cnt0++;}
            else{cnt1++;}
        }
        if(s[0]=='1'&&s[n-1]=='1'){
            int y=0;
            for(int i=1;i<n-1;i++){
                if(s[i]=='1'){y++;}
            }
            return min(cnt1,min(abs(1-cnt1),min(y,cnt0)));
        }
        return min(cnt1,min(abs(1-cnt1),cnt0));
    }
};