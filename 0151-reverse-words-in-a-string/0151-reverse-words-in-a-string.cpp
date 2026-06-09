class Solution {
public:
    string reverseWords(string s){
        int n=s.size();
        stack<string> st;
        int i=0;
        int sti=-1,edi=-1;
        while(i<s.size()){
            if(sti==-1){
                if(s[i]!=' '){sti=i;}
            }
            else{
                if(s[i]==' '){st.push(s.substr(sti,i-sti));sti=-1;}
            }
            i++;
        }
        if(s[n-1]!=' '){st.push(s.substr(sti,n-sti));}
        string ans="";
        while(!st.empty()){
            if(ans==""){
                ans+=st.top();st.pop();
            }
            else{ans+=" "+st.top();st.pop();}
        }
        return ans;
    }
};