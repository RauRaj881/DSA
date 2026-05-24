class Solution {
public:
    int passwordStrength(string ps){
        unordered_set<char> st;
        int ans=0;
        for(auto it:ps){
            if(it>='a'&&it<='z'){
                if(!st.count(it)){ans+=1;}
            }
            else if(it>='A'&&it<='Z'){
                if(!st.count(it)){ans+=2;}
            }
            else if(it>='0'&&it<='9'){
                if(!st.count(it)){ans+=3;}
            }
            else{
                if(!st.count(it)){ans+=5;}
            }
            st.insert(it);
        }
        return ans;
        
    }
};