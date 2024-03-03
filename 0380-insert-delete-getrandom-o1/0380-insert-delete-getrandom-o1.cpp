class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> vals;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            mp[val] = vals.size(); // insert at last index
            vals.push_back(val);
            return true;
        } 
        return false;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;
        int idx = mp[val];
        int last = vals.back();
        vals[idx] = last; // remove the val by overwriting it
        mp[last] = idx; // update the index in map
        vals.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */