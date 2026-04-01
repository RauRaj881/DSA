class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && asteroids[i]<0 && st.top()>0 &&abs(st.top())<abs(asteroids[i])){
                st.pop();
            }
            if(st.empty()){st.push(asteroids[i]);}
            else if(asteroids[i]<0 && st.top()>0 &&abs(st.top())>abs(asteroids[i])){st=st;}
            else if(asteroids[i]<0 &&st.top()>0 &&abs(st.top())==abs(asteroids[i])){st.pop();}
            else{st.push(asteroids[i]);}
        }
        while(!st.empty()){v.push_back(st.top());st.pop();}
        reverse(v.begin(),v.end());
        return v;
    }
};