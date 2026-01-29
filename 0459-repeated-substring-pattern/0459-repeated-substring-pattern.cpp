class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string p=s+s;
        for(int i=1;i<n;i++){
            if(p.substr(i,n)==s){return true;}
        }
        return false;
    }
};