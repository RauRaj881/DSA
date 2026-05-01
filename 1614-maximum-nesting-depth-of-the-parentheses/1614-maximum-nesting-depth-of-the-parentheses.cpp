class Solution {
public:
    int maxDepth(string s) {
        int maxno=0;
        int p=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){p++;}
            else if(s[i]==')'){
                p--;
            }
            maxno=max(maxno,p);
        }
        return maxno;
    }
};