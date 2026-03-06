class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0,cr=0;
        if(s[0]=='1'){cnt++;cr=1;}
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){if(cnt!=cr){return false;}else{cnt=cr;}}
            else{cr=0;}
        }
        return true;
        
    }
};