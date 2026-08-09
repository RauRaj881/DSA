class Solution {
public:
    int h=0;
    long long ans=0;
    void dfs(int nd,vector<vector<int>>& adj,int prt,int d){
        h=max(h,d);
        for(auto it:adj[nd]){
            if(it!=prt){
                dfs(it,adj,nd,d+1);
            }
        }
    }
    void dfs2(int nd,vector<vector<int>>& adj,int prt,vector<int>& nums,int d){
        //d++;
        ans+=(long long)nums[nd]*(h-d+1);
        for(auto it:adj[nd]){
            if(it!=prt){
                dfs2(it,adj,nd,nums,d+1);
            }
        }
        
    }
    long long weightedSum(vector<int>& par,vector<int>& nums){
        int n=par.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(par[i]!=-1){
                adj[i].push_back(par[i]);
                adj[par[i]].push_back(i);
            }
        }
        //h=0,ans=0;
        //int h=1;
        dfs(0,adj,-1,1);
        dfs2(0,adj,-1,nums,1);
        return ans;
        
    }
};