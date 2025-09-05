class Solution {
public:
int f(vector<int> &heights){
    stack<int> st;
        int maxa=0;
        int pse=-1,nse;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int x=st.top();
                st.pop();
                if(!st.empty()){pse=st.top();}
                else{pse=-1;}
                maxa=max(maxa,heights[x]*(i-(pse+1)));
            }
            st.push(i);
        }
        nse=heights.size();
        while(!st.empty()){
             int x=st.top();
            st.pop();
            if(!st.empty()){pse=st.top();}
                else{pse=-1;}
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