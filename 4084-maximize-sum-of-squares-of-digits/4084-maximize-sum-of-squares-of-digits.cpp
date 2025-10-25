class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum>num*9){return ans;}
        while(sum!=0){
            if(sum>=9){
                ans+='9';
                sum-=9;
            }
            else{
                ans+=char(sum+'0');
                sum=0;
            }
        }
        if(ans.size()!=num){
            int diff=num-ans.size();
            string last(diff,'0');
            ans+=last;
        }
        return ans;
    }
};