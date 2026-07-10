class Solution {
public:
    string simplifyPath(string p){
        int n=p.size();
        string ans="";
        int i=0;
        stack<string> st;
        while(i<n){
            int j=i;
            string tp="";
            while(j<n&&p[j]=='/'){j++;}
            while(j<n&&p[j]!='/'){tp+=p[j];j++;}
            if(tp==""){break;}
            else if(tp==".."){if(!st.empty())st.pop();i=j;}
            else if(tp=="."){i=j;}
            else{string tp2="/"+tp;st.push(tp2);i=j;}
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        if(ans.empty()){return "/";}
        return ans;
    }
};