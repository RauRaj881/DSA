class Solution {
public:
    bool parseBoolExpr(string exp){
        int n=exp.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(exp[i]!=')'){st.push(exp[i]);}
            else{
                int cntt=0,cntf=0;
                while(st.top()!='('){
                    if(st.top()=='f'){cntf++;}
                    else if(st.top()=='t'){cntt++;}
                    st.pop();
                }
                st.pop();
                if(st.top()=='|'){
                    st.pop();
                    if(cntt>0){st.push('t');}
                    else{st.push('f');}
                }
                else if(st.top()=='&'){
                    st.pop();
                    if(cntf>0){st.push('f');}
                    else{st.push('t');}
                }
                else{
                    st.pop();
                    if(cntt>0){st.push('f');}
                    else{st.push('t');}
                }
            }
        }
        return st.top()=='t';
    }
};