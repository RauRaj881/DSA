class Solution {
public:
    string reverseWords(string s){
        int n=s.size();
        string ans="";
        string tp="";
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){tp+=s[i];}
            else{
                if(i<n-1&&s[i+1]!=' '){
                    string x(tp.rbegin(), tp.rend());
                    ans+=' '+x;
                    tp="";
                }
            }
        }
        if(s[0]!=' '){string x(tp.rbegin(), tp.rend());
                    ans+=' '+x;}
        return ans.substr(1);
    }
};