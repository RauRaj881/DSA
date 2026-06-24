class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast){
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<ast.size();i++){
            bool pos=true;
            while(!st.empty()&&st.top()>0&&ast[i]<0){
                if(abs(ast[i])>st.top()){st.pop();}
                else if(abs(ast[i])==st.top()){pos=false;st.pop();break;}
                else{pos=false;break;}
            }
            if(pos){st.push(ast[i]);}
        }
        while(!st.empty()){ans.push_back(st.top());st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};