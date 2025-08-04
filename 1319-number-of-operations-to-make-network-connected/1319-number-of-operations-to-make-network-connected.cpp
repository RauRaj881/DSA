class Solution {
public:
       int findUpar(vector<int> &parent,int node){
        if(node==parent[node]){return node;}
        return findUpar(parent,parent[node]);
        }
        int x=0;
        void unionbyrank(int u,int v,vector<int> &parent,vector<int> &rank){
            int ulp_u=findUpar(parent,u);
            int ulp_v=findUpar(parent,v);
            if(ulp_u==ulp_v){
                x++;
                return;
            }
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else if(rank[ulp_u]==rank[ulp_v]){
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        for(int i=0;i<connections.size();i++){
            unionbyrank(connections[i][0],connections[i][1],parent,rank);
        }
        int y=0;
        for(int j=0;j<n;j++){
            if(parent[j]==j){
                y++;
            }
        }
        if(x>=y-1){return y-1;}
        return -1;
    }
};