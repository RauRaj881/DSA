class Solution {
public:
    int binaryGap(int n) {
        int cr=1;
        int lt=-1;
        int ans=0;
        for(int i=0;i<=31;i++){
            cr=1<<i;
            if((n&cr)!=0){
                if(lt==-1){lt=i;}
                else{ans=max(i-lt,ans);lt=i;}
            }
        }
        return ans;
    }
};