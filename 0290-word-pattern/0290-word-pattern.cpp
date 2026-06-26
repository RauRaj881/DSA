class Solution {
public:
    bool wordPattern(string ptn, string s){
        int n=ptn.size();
        int sp=0;
        for(auto it:s){
            if(it==' '){sp++;}
        }
        if(n!=sp+1){return false;}
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int j=0;        
        for(int i=0;i<n;i++){
            char ch=ptn[i];
            string tp="";
            while(j<s.size()&&s[j]!=' '){
                tp+=s[j];
                j++;
            }
            j++;
            if(mp1.count(ch)){if(mp1[ch]!=tp){return false;}}
            else if(mp2.count(tp)){if(mp2[tp]!=ch){return false;}}
            else{mp1[ch]=tp;mp2[tp]=ch;}
        }
        return true;
    }
};