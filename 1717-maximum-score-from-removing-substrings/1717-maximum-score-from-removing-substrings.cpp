class Solution {
public:
int f(string &s,int vl,string tar){
    stack<char> st;
    int x=0;
    for(int i=0;i<s.size();i++){
        if(!st.empty()&&st.top()==tar[0]&&s[i]==tar[1]){
            x+=vl;
            st.pop();
        }
        else{st.push(s[i]);}
    }
    string tp="";
    while(!st.empty()){
        tp+=st.top();
        st.pop();
    }
    reverse(tp.begin(),tp.end());
    s=tp;
    return x;
}
    int maximumGain(string s, int x, int y){
        int ans=0;
        if(y>x){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        ans+=f(s,x,"ab");
        ans+=f(s,y,"ba");
        return ans;
    }
};