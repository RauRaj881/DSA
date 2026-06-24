class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        stack<int> st;
        int h=0;
        for(int i=0;i<num.length();i++){
            while(!st.empty() &&st.top()>num[i] && h<k){
                st.pop();h++;
            }
            st.push(num[i]);
        }
        while(k>h){st.pop();h++;}
        while(!st.empty()){s.push_back(st.top());st.pop();}
        while(s.size()!=0 && s.back()=='0'){s.pop_back();}
        reverse(s.begin(),s.end());
        if(num.size()==k || s.empty()){s="0";}
        return s;
    }
};