class Solution {
public:
    int trap(vector<int>& hgt){
        int n=hgt.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&hgt[st.top()]<=hgt[i]){
                int btw=hgt[st.top()];
                st.pop();
                if(st.empty()){break;}
                int lt=hgt[st.top()];
                int rt=hgt[i];
                int ht=min(rt,lt)-btw;
                int wd=i-st.top()-1;
                ans+=(wd*ht);
            }
            st.push(i);
        }
        return ans;
        
    }
};