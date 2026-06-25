class Solution {
public:
    int largestRectangleArea(vector<int>& h){
        int n=h.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&h[st.top()]>h[i]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&h[st.top()]>h[i]){
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(h[i]*(nse[i]-pse[i]-1),ans);
        }
        return ans;
    }
};