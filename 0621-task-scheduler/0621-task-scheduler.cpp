class Solution {
public:
    int leastInterval(vector<char>& tsk, int n){
        int m=tsk.size();
        vector<int> fr(26,0);
        for(auto it:tsk){fr[it-'A']++;}
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){if(fr[i]>0){pq.push({fr[i],i});}}
        queue<pair<int,int>> cool;
        int time=0;
        while(!pq.empty()||!cool.empty()){
            while(!cool.empty()&&cool.front().second<=time){
                int i=cool.front().first;
                cool.pop();
                pq.push({fr[i],i});
            }
            if(!pq.empty()){
                int i=pq.top().second;
                pq.pop();
                fr[i]--;
                if(fr[i]>0){cool.push({i,time+n+1});}
            }
            time++;
        }
        return time;
    }
};