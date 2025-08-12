class Solution {
public:
bool dfs(int node,int col,vector<vector<int>>& graph,vector<int> & visited){
    visited[node]=col;
        for(int j=0;j<graph[node].size();j++){
            if(visited[graph[node][j]]==-1){
                if(dfs(graph[node][j],1-col,graph,visited)==false){return false;}
            }
            else if(visited[graph[node][j]]==col){return false;}
        }
        return true;
           
}
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> visited(graph.size(),-1);
       for(int i=0;i<graph.size();i++){
        if(visited[i]==-1){
            if(dfs(i,0,graph,visited)==false){return false;}
        }
       }
       return true;
    }
};