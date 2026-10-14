class Solution {
public:
    string removeKdigits(string num, int k){
        int n=num.size();
        string st="";
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.back()>num[i]&&k>0){
                st.pop_back();
                k--;
            }
            st+=num[i];
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        int i=0;
        while(i<st.size()&&st[i]=='0'){i++;}
        if(i==st.size()){return "0";}
        return string(st.begin()+i,st.end());
    }
};