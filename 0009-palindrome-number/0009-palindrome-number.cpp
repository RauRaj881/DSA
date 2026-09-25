class Solution {
public:
    bool isPalindrome(long x){
        if(x<0){return false;}
        long cr=0;
        long ori=x;
        while(x>0){
            int tp=x%10;
            cr=cr*10+tp;
            x/=10;
        }
        return cr==ori;
    }
};