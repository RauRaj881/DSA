/*class Solution {
public:
int solve(vector<int> &heights){
    stack<int> st;
    int maxa=0;
    for(int j=0;j<heights.size();j++){
        while(!st.empty()&&heights[st.top()]>heights[j]){
            int x=st.top();
            st.pop();
            int pse=-1;
            if(!st.empty()){pse=st.top();}
            int width = j - pse - 1;
            if (width >= heights[x])
            maxa = max(maxa, heights[x] * heights[x]);
        }
        st.push(j);
    }
    int nse=heights.size();
    while(!st.empty()){
        int x=st.top();
        st.pop();
        int pse=-1;
        if(!st.empty()){pse=st.top();}
        int width = nse - pse - 1;
        if (width >= heights[x])
        maxa = max(maxa, heights[x] * heights[x]);
    }
    return maxa;
}
    int maximalSquare(vector<vector<char>>& matrix) {
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
            int area=solve(heights);
            maxa=max(maxa,area);
        }
        return maxa;
    }
};*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxa=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    if(i==0||j==0){dp[i][j]=1;}
                    else{dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));}}
                    maxa=max(maxa,dp[i][j]*dp[i][j]);
            }
        }
        return maxa;
    }
};