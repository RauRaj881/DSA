class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& pre){
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int tp=q.front();
            ans.push_back(tp);
            q.pop();
            for(auto it:adj[tp]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n){return ans;}
        return {};
    }
};