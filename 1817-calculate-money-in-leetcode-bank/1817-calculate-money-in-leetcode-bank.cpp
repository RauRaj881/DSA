class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%7==0){sum+=7+(i/7-1);}
            else{sum+=i/7+i%7;}
        }
        return sum;
    }
};