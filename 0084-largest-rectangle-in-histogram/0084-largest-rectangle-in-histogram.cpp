class Solution {
public:
    int largestRectangleArea(vector<int>& h){
        int n=h.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&h[st.top()]>h[i]){
                int ht=h[st.top()];
                st.pop();
                int pse=-1;
                if(!st.empty()){pse=st.top();}
                int wd=i-pse-1;
                ans=max(ans,ht*wd);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ht=h[st.top()];
            st.pop();
            int pse=-1;
            if(!st.empty()){pse=st.top();}
            int wd=n-pse-1;
            ans=max(ans,ht*wd);
        }
        return ans;
    }
};