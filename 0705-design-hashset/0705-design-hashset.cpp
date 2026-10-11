class MyHashSet {
public:
vector<list<int>> mp;
int sz=1005;
    MyHashSet(){
        mp.resize(sz);
    }
    
    void add(int key){
        int idx=key%sz;
        for(auto it:mp[idx]){
            if(it==key){return;}
        }
        mp[idx].push_back(key);
    }
    
    void remove(int key){
        int idx=key%sz;
        for(auto it=mp[idx].begin();it!=mp[idx].end();it++){
            if(*it==key){
                mp[idx].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key){
        int idx=key%sz;
        for(auto it:mp[idx]){
            if(it==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */