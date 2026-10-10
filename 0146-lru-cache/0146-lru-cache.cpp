class LRUCache {
public:
list<pair<int,int>> dll;
map<int,list<pair<int,int>>::iterator> mp;
int sz=0;
    LRUCache(int cap){
        sz=cap;
    }
    
    int get(int key){
        if(!mp.count(key)){return -1;}
        auto it=mp[key];
        int val=it->second;
        dll.erase(it);
        dll.push_front({key,val});
        mp[key]=dll.begin();
        return val;
    }
    
    void put(int key,int val){
        if(mp.count(key)){
            auto it=mp[key];
            dll.erase(it);
        }
        dll.push_front({key,val});
        mp[key]=dll.begin();
        if(dll.size()>sz){
            auto it=prev(dll.end());
            int lt=it->first;
            dll.erase(it);
            mp.erase(lt);
        }
        mp[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */