class Solution {
public:
int f(vector<int>& h){
    int m=h.size();
    stack<int> st;
    int ans=0;
    for(int i=0;i<m;i++){
        while(!st.empty()&&h[st.top()]>h[i]){
            int ht=h[st.top()];
            int pse=-1;
            st.pop();
            if(!st.empty()){pse=st.top();}
            int wd=i-pse-1;
            ans=max(ans,wd*ht);
        }
        st.push(i);
    }
    while(!st.empty()){
        int pse=-1;
        int ht=h[st.top()];
        st.pop();
        if(!st.empty()){pse=st.top();}
        int wd=m-pse-1;
        ans=max(ans,wd*ht);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        int mx=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){h[j]++;}
                else{h[j]=0;}
            }
            mx=max(mx,f(h));
        }
        return mx;
    }
};