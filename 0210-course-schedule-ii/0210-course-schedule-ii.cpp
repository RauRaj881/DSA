class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& ed){
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){if(indeg[i]==0){q.push(i);}}
        vector<int> ans;
        while(!q.empty()){
            int cr=q.front();
            q.pop();
            ans.push_back(cr);
            for(auto it:adj[cr]){
                indeg[it]--;
                if(indeg[it]==0){q.push(it);}
            }
        }
        if(ans.size()==n){return ans;}
        return {};
    }
};