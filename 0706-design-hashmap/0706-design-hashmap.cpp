class MyHashMap {
public:
vector<list<pair<int,int>>> mp;
int sz=1005;
    MyHashMap(){
        mp.resize(sz);
    }
    
    void put(int key, int val){
        int idx=key%sz;
        for(auto &it:mp[idx]){
            if(it.first==key){
                it.second=val;
                return;
            }
        }
        mp[idx].push_back({key,val});
    }
    
    int get(int key){
        int idx=key%sz;
        for(auto it:mp[idx]){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key){
        int idx=key%sz;
        for(auto it=mp[idx].begin();it!=mp[idx].end();it++){
            if(it->first==key){
                mp[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */