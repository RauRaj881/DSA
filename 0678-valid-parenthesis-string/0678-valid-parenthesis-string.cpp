class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
        if(s.size()==1 && s[0]!='*'){return 0;}
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){min++;max++;}
            else if(s[i]==')'){min--;max--;}
            else{
                min--;
                max++;
            }
            if(min<0){min=0;}
            if(max<0){return 0;}
        }
        return min==0;
    }
};