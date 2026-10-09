class Solution {
public:
    bool checkPerfectNumber(int num){
        int ans=0;
        for(int i=1;i*i<=num;i++){
            if(i==num){continue;}
            if(num%i==0){
                ans+=i;
                if(i*i!=num&&i!=1){
                    ans+=num/i;
                }
            }
        }
        return ans==num;
    }
};