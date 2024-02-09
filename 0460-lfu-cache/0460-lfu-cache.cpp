class LFUCache {
    int cap = 0;
    int minFreq = 0; // keeps track of min freq
    unordered_map<int, int> keyVal;
    unordered_map<int, int> keyFreq;
    unordered_map<int, list<int>> freqList;
    // freqList is a map of freq to a Doubly Linked List of keys
    // in DLL, front node/key will be least recent
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (keyVal.find(key) == keyVal.end())
            return -1;
        updateFreq(key);
        return keyVal[key];   
    }
    
    void put(int key, int value) {
        // 1. update the value if key exists
        if (keyVal.find(key) != keyVal.end()) {
            keyVal[key] = value;
            // 2. update the freq of current key
            updateFreq(key);
        }
        else {
            // 3. insert if size <= max capacity
            // if not then evict first the LFU key and then insert
            if (keyVal.size() < cap) {
                keyVal[key] = value;
            } else {
                int keyToEvict = freqList[minFreq].front();
                freqList[minFreq].pop_front(); // remove LRU key with min frequency
                keyVal.erase(keyToEvict);
                keyFreq.erase(keyToEvict);
                keyVal[key] = value;
            }
            // 4. update the freq of the new key
            keyFreq[key] = 1;
            minFreq = 1;
            freqList[1].push_back(key);
        }
    }
private:
    void updateFreq(int key) {
        // 1. update the frequency
        int curFreq = keyFreq[key];
        // 2. remove the key from freqList[curFreq] & insert into freqList[freq++]
        freqList[curFreq].remove(key);
        // 3. increase minFreq if key was erased from freqList[minFreq] & it became empty
        if (freqList[minFreq].empty())
            minFreq++;
        // 4. insert key at back of DLL with new val
        keyFreq[key] = curFreq + 1;
        freqList[curFreq + 1].push_back(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */