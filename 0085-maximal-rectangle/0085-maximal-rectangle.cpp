class Solution {
public:
int f(vector<int> &heights){
    stack<int> st;
    int maxa=0;
    for(int j=0;j<heights.size();j++){
        while(!st.empty()&&heights[j]<heights[st.top()]){
            int x=st.top();
            st.pop();
            int pse=-1;
            if(!st.empty()){pse=st.top();}
            maxa=max(maxa,heights[x]*(j-(pse+1)));
        }
        st.push(j);
    }
    int nse=heights.size();
    while(!st.empty()){
        int x=st.top();
        st.pop();
        int pse=-1;
        if(!st.empty()){pse=st.top();}
        maxa=max(maxa,heights[x]*(nse-(pse+1)));
    }
    return maxa;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxa=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            int area=f(heights);
            maxa=max(maxa,area);
        }
        return maxa;
    }
};