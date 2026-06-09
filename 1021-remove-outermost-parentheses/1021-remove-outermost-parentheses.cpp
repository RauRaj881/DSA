class Solution {
public:
    string removeOuterParentheses(string s){
        string ans="";
        int cnt=0;
        for(auto it:s){
            if(it=='('){cnt--;}
            else{cnt++;}
            if(cnt==0||(cnt==-1&&it=='(')){continue;}
            else{ans+=it;}
        }
        return ans;
    }
};