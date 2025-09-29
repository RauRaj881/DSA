class Solution {
public:
    int minAddToMakeValid(string s) {
        int p=0;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                sum++;
            }
            else{sum--;}
            if(sum<0){p++;sum=0;}
        }
        return p+sum;
    }
};