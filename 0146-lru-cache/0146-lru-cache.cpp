class LRUCache {
public:
int cp=-1;
list<pair<int,int>> dll;
unordered_map<int,list<pair<int,int>>::iterator> mp;
    LRUCache(int cap){
        cp=cap;
    }
    
    int get(int key){
        if(!mp.count(key)){return -1;}
        auto it=mp[key];
        int vl=mp[key]->second;
        dll.erase(it);
        dll.push_front({key,vl});
        mp[key]=dll.begin();
        return mp[key]->second;
    }
    
    void put(int key, int vl){
        if(mp.count(key)){
            auto it=mp[key];
            dll.erase(it);
        }
        else if(dll.size()==cp){
            auto it=dll.back();
            mp.erase(it.first);
            dll.pop_back();
        }
        dll.push_front({key,vl});
        mp[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */