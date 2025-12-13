class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int i1=0,i2=0;
        if(s.size()==0){return true;}
        while(i1<n1&&i2<n2){
            if(s[i1]==t[i2]){
                i1++;i2++;
            }
            else{
                i2++;
            }
            if(i1==n1){return true;}
        }
        return false;
    }
};