class EventManager {
public:
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mp;
    EventManager(vector<vector<int>>& events){
        for(int i=0;i<events.size();i++){
            int pt=events[i][1];
            int id=events[i][0];
            pq.push({pt,-id});
            mp[id]=pt;
        }
    }
    void updatePriority(int eId, int nP){
        pq.push({nP,-eId});
        mp[eId]=nP;
    }
    
    int pollHighest(){
        if(pq.empty()){return -1;}
        while(!pq.empty()&&(!mp.count(-pq.top().second))||(!pq.empty()&&mp[-pq.top().second]!=pq.top().first)){

            pq.pop();
        }
        if(pq.empty()){return -1;}
        int x=pq.top().second;
        mp.erase(-x);
        pq.pop();
        return -x;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */