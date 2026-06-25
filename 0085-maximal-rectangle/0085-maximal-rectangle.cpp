class Solution {
public:
int f(vector<int> &h){
    int mx=0;
    stack<int> st;
    int n=h.size();
    for(int i=0;i<n;i++){
        while(!st.empty()&&h[st.top()]>h[i]){
            int ht=h[st.top()];
            int pse=-1;
            st.pop();
            if(!st.empty()){pse=st.top();}
            int wd=i-pse-1;
            mx=max(wd*ht,mx);
        }
        st.push(i);
    }
    while(!st.empty()){
        int ht=h[st.top()];
        int pse=-1;
        st.pop();
        if(!st.empty()){pse=st.top();}
        int wd=n-pse-1;
        mx=max(wd*ht,mx);
    }
    return mx;
}
    int maximalRectangle(vector<vector<char>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        vector<int> h(n);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='1'){h[j]++;}
                else{h[j]=0;}
            }
            ans=max(ans,f(h));
        }
        return ans;
    }
};