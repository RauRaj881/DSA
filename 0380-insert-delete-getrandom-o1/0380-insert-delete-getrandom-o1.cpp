class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mp;
    RandomizedSet() {}
    bool insert(int val) {
        if(!mp.count(val)){
            v.push_back(val);
            int index=v.size()-1;
            mp[val]=index;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int index=mp[val];
            v[index]=v.back();
            mp[v.back()]=index;
            mp.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randindex= rand()%v.size();
        return v[randindex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */