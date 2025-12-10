class Solution {
public:
void dfx(int i,vector<int> &path, vector<vector<int>> &adj,vector<int> &visited,
vector<vector<int>> &res){
          visited[i]=1;
          path.push_back(i);
          for(int j=0;j<adj[i].size();j++){
              if(visited[adj[i][j]]==0){
                  dfx(adj[i][j],path,adj,visited,res);
          }
      }
  }
    vector<int> processQueries(int V, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        vector<vector<int>> res;
        vector<int> visited(V,0);
        for(int i=0;i<adj.size();i++){
            vector<int> path;
            if(visited[i]==0){
                dfx(i,path,adj,visited,res);
                res.push_back(path);
            }
        }
        vector<int> ans;
        vector<int> id(V);
        for(int i=0;i<res.size();i++){
            for(int x:res[i]){
                id[x]=i;
            }
        }
        vector<set<int>> vec(res.size());
        for(int i=0;i<V;i++){
            vec[id[i]].insert(i);
        }
        for(int i=0;i<q.size();i++){
            int ft=q[i][0];
            int sd=q[i][1];
            int id2=id[sd-1];
            if(ft==1){
                if(vec[id2].count(sd-1)){
                    ans.push_back(sd);
                }
                else if(vec[id2].empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(*vec[id2].begin()+1);
                }
            }
            else{
               vec[id2].erase(sd-1);
            }
        }
        return ans;
    }
};