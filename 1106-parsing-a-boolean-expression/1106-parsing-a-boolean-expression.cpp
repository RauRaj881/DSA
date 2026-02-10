class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]!=')'){
                st.push(exp[i]);
            }
            else{
                unordered_map<char,int> mp;
                while(!(st.top()=='!'||st.top()=='&'||st.top()=='|')){
                    mp[st.top()]++;st.pop();
                }
                if(st.top()=='|'){
                    if(mp.count('t')){
                        st.pop();
                        st.push('t');
                    }
                    else{
                        st.pop();
                        st.push('f');
                    }
                }
                else if(st.top()=='&'){
                    if(mp.count('f')){
                        st.pop();
                        st.push('f');
                    }
                    else{
                        st.pop();
                        st.push('t');
                    }
                }
                else{
                    if(mp.count('f')){
                        st.pop();
                        st.push('t');
                    }
                    else{
                        st.pop();
                        st.push('f');
                    }
                }
            }
        }
        return st.top()=='t';
    }
};