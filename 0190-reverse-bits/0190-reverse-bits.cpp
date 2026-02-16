/*class Solution {
public:
    int reverseBits(int n) {
        string s="";
        while(n!=0){
            s+=char(n%2+'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        int sz=s.size();
        string p(32-sz,'0');
        s=p+s;
        reverse(s.begin(),s.end());
        int ans=0;
        for(int i=31;i>=0;i--){
            if(s[i]=='1'){ans+=(1<<(31-i));}
        }
        return ans;
    }
};*/
class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            ans<<=1;
            ans=ans|(n&1);
            n>>=1;
        }
        return ans;
    }
};