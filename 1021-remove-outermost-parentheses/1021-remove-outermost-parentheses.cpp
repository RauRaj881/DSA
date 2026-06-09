class Solution {
public:
    string removeOuterParentheses(string s) {
        int t=0,p=0;
        vector<int> v;        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(') t++;
            else if(c==')') p++;
            if(t==p){v.push_back(i);
        t=0;
            p=0;
            }
            if(t==1){
                v.push_back(i);
                }
        }
        int u=v.size();
        for(int j=0;j<u;j++){
          int index=v[j]-j;
           s.erase(s.begin()+index);
        }
        return s;
    }
};