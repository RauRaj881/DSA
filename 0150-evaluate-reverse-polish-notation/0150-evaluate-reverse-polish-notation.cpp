class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n=t.size();
        if(n==1){return stoi(t[0]);}
        stack<string> st1;
        queue<string> st2;
        int ans;
        for(int i=0;i<n;i++){
            if(st2.empty()){
                if(t[i]=="+"||t[i]=="-"||t[i]=="*"||t[i]=="/"){
                    if(st1.size()<2){st2.push(t[i]);}
                    else{
                        string s1=st1.top();st1.pop();
                        string s2=st1.top();st1.pop();
                        int x1=stoi(s1),x2=stoi(s2);
                        if(t[i]=="+"){ans=x1+x2;}else if(t[i]=="-"){ans=x2-x1;}
                        else if(t[i]=="*"){ans=x1*x2;}else{ans=x2/x1;}
                        st1.push(to_string(ans));
                    }
                }
                else{st1.push(t[i]);}
            }
            else{
                if(t[i]=="+"||t[i]=="-"||t[i]=="*"||t[i]=="/"){st2.push(t[i]);}
                else{
                    st1.push(t[i]);
                }
                if(st1.size()>=2){
                    string op=st2.front();
                    if(st1.size()>=2){
                    string s3=st1.top();st1.pop();
                    string s4=st1.top();st1.pop();
                    int y1=stoi(s3),y2=stoi(s4);
                    if(op=="+"){ans=y1+y2;}else if(op=="-"){ans=y2-y1;}
                    else if(op=="*"){ans=y1*y2;}else{ans=y2/y1;}
                    st1.push(to_string(ans));
                }
                }
            }
        }
            return ans;
    }
};