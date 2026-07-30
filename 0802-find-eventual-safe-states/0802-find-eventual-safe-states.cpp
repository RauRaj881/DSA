class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> outdeg(n,0);
        vector<vector<int>> revadj(n);
        for(int i=0;i<adj.size();i++){
            for(auto it:adj[i]){
                outdeg[i]++;
                revadj[it].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0){q.push(i);}
        }
        vector<int> ans;
        while(!q.empty()){
            int cr=q.front();
            ans.push_back(cr);
            q.pop();
            for(auto it:revadj[cr]){
                outdeg[it]--;
                if(outdeg[it]==0){q.push(it);}
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};