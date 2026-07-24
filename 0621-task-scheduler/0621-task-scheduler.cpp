class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        priority_queue<pair<int,int>> pq;
        queue<vector<int>> q;
        vector<int> v(26,0);
        for(auto it:tasks){v[it-'A']++;}
        for(int i=0;i<26;i++){
            if(v[i]>0){pq.push({v[i],i});}
        }
        int tm=0;
        while(!pq.empty()||!q.empty()){
            while(!q.empty()&&tm-q.front()[2]>n){
                pq.push({q.front()[1],q.front()[0]});
                q.pop();
            }
            if(!pq.empty()){
                int fr=pq.top().first;
                int ch=pq.top().second;
                fr--;
                pq.pop();
                if(fr>0){
                    q.push({ch,fr,tm});
                }
            }
            tm++;
        }
        return tm;
    }
};