class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& prs) {
        int n=prs.size();
        map<int,vector<int>> adj;
        unordered_map<int,int> indeg;
        unordered_map<int,int> outdeg;
        for(int i=0;i<n;i++){
            int st=prs[i][0];
            int ed=prs[i][1];
            adj[st].push_back(ed);
            indeg[ed]++;
            outdeg[st]++;
        }
        stack<int> st;
        //vector<int> vis(n,0);
        for(auto it:outdeg){
            int nd=it.first;
            if(outdeg[nd]==indeg[nd]+1){
                st.push(nd);break;
            }
        }
        if(st.empty()){st.push(prs[0][0]);}
        vector<int> ans;
        while(!st.empty()){
            int nd=st.top();
            if(!adj[nd].empty()){
                st.push(adj[nd].back());
                adj[nd].pop_back();
            }
            else{
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        vector<vector<int>> ans2;
        for(int i=1;i<ans.size();i++){
            ans2.push_back({ans[i-1],ans[i]});
        }
        return ans2;
    }
};