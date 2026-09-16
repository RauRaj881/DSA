class Solution {
public:
    bool parseBoolExpr(string exp){
        int n=exp.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(exp[i]!=')'){
                st.push(exp[i]);
            }
            else{
                unordered_map<char,int> mp;
                while(!(st.top()=='|'||st.top()=='&'||st.top()=='!')){
                    mp[st.top()]++;st.pop();
                }
                if(st.top()=='|'){
                    st.pop();
                    if(mp.count('t')){st.push('t');}
                    else{st.push('f');}
                }
                else if(st.top()=='&'){
                    st.pop();
                    if(mp.count('f')){st.push('f');}
                    else{st.push('t');}
                }
                else{
                    st.pop();
                    if(mp.count('t')){st.push('f');}
                    else{st.push('t');}
                }
            }
        }
        return st.top()=='t';
    }
};