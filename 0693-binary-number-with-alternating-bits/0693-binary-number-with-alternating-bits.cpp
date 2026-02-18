/*class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x=1;
        int cr;
        if((n&1)==0){cr=0;}
        else{cr=1;}
        x<<=1;
        int dr;
        for(int i=1;i<31;i++){
            if(cr==1){
               if((x&n)!=0){return false;}
               else{cr=0;x<<=1;} 
            }
            else{
                if((x&n)!=0){x<<=1;cr=1;}
                else{dr=i;break;}
            }
        }
        for(int i=dr;i<31;i++){
            if((x&n)!=0){return false;}
            else{x<<=1;}
        }
        return true;
    }
};*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long x=(n>>1);
        long xr=x^n;
        return ((xr&(xr+1))==0);
    }
};