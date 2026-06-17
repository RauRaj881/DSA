class Solution {
public:
    string processStr(string s){
        string ans="";
        for(auto it:s){
            if(islower(it)){ans+=it;}
            else if(it=='*'){
                int n=ans.size();
                if(n>0)ans=ans.substr(0,n-1);
            }
            else if(it=='#'){
                ans+=ans;
            }
            else{reverse(ans.begin(),ans.end());}
        }
        return ans;
    }
};