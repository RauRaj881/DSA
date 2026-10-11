class MyHashSet {
public:
vector<list<int>> v;
int sz=1005;
    MyHashSet(){
        v.resize(sz);
    }
    
    void add(int key){
        int idx=key%sz;
        for(auto it:v[idx]){
            if(it==key){return;}
        }
        v[idx].push_back(key);
    }
    
    void remove(int key){
        int idx=key%sz;
        for(auto it=v[idx].begin();it!=v[idx].end();it++){
            if(*it==key){
                v[idx].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key){
        int idx=key%sz;
        for(auto it:v[idx]){
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