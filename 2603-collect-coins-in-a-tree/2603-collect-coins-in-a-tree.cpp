class Solution {
public:
    int collectTheCoins(vector<int>& coins,vector<vector<int>>& ed){
        int n=coins.size();
        vector<unordered_set<int>> adj(n);
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1&&coins[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int lv=q.front();
            q.pop();
            for(auto it:adj[lv]){
                adj[it].erase(lv);
                if(adj[it].size()==1 && coins[it]==0){
                    q.push(it);
                }
            }
            adj[lv].clear();
        }
        while(!q.empty()){q.pop();}
        for(int i=0;i<n;i++){
            if(adj[i].size()==1&&coins[i]==1){q.push(i);}
        }
        // First layer removal - collect all leaves first, then remove
        queue<int> temp;
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            int lv=temp.front();
            temp.pop();
            for(auto it:adj[lv]){
                adj[it].erase(lv);
            }
            adj[lv].clear();
        }
        
        // Second layer removal - collect all new leaves first, then remove
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){q.push(i);}
        }
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            int lv=temp.front();
            temp.pop();
            for(auto it:adj[lv]){
                adj[it].erase(lv);
            }
            adj[lv].clear();
        }
        
        int rm=0;
        for(int i=0;i<n;i++){
            if(adj[i].size()>0){rm++;}
        }
        if(rm<=1){return 0;}
        return (rm-1)*2;
    }
};