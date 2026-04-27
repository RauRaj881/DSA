class Solution {
public:
    int maximumGain(string s, int x, int y){
        int n=s.size();
        int cnta=0,cntb=0;
        int ans=0;
        if(y>x){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        for(int i=0;i<n;i++){
            if(s[i]=='a'){cnta++;}
            else if(s[i]=='b'){
                if(cnta>0){cnta--;ans+=x;}
                else{cntb++;}
            }
            else{ans+=min(cnta,cntb)*y;cnta=0;cntb=0;}
        }
        ans+=min(cnta,cntb)*y;
        return ans;
    }
};