/*class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        string t=s;
        int ans=0;
        while(t!="1"){
            ans++;
            int sz=t.size();
            if(t[sz-1]=='0'){
                t = t.substr(0, sz - 1);
            }
            else{
                int i=sz-1;
                while(i>=0){
                    if(t[i]=='0'){
                        t[i]='1';break;
                    }
                    i--;
                }
                if(i<0){
                    string ad(sz, '0');
                    t="1"+ad;
                }
                else{
                    for(int x=i+1;x<t.size();x++){
                        t[x]='0';
                    }
                }
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int n=s.size();
        int carry=0;
        for(int i=n-1;i>0;i--){
            int cr=s[i]-'0'+carry;
            if(cr%2==1){
                ans+=2;
                carry=1;
            }
            else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};