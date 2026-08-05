class Solution {
public:
    int leastInterval(vector<char>& t,int n){
        priority_queue<pair<int,int>> pq;
        queue<vector<int>> q;
        vector<int> fr(26,0);
        for(int i=0;i<t.size();i++){
            fr[t[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(fr[i]>0){
                pq.push({fr[i],i});
            }
        }
        int tm=0;
        while(!pq.empty()||!q.empty()){
            while(!q.empty()&&q.front()[0]==tm){
                int ch=q.front()[1];
                int crfr=q.front()[2];
                pq.push({crfr,ch});
                q.pop();
            }
            if(!pq.empty()){
                int crfr=pq.top().first;
                int ch=pq.top().second;
                pq.pop();
                crfr--;
                if(crfr>0){
                    q.push({tm+n+1,ch,crfr});
                }
            }
            tm++;
        }
        return tm;
    }
};