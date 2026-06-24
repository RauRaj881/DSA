class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast){
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<ast.size();i++){
            bool alive=true;
            while(!st.empty()&&st.top()>0&&ast[i]<0){
                if(abs(ast[i])>st.top()){st.pop();}
                else if(abs(ast[i])==st.top()){alive=false;st.pop();break;}
                else{alive=false;break;}            
            }
            if(alive){st.push(ast[i]);}
        }
        while(!st.empty()){ans.push_back(st.top());st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};