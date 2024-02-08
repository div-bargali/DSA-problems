#include <unordered_map>

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    std::unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;
    
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* keyNode = mp[key];
            moveToHead(keyNode);
            return keyNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* keyNode = mp[key];
            keyNode->val = value;
            moveToHead(keyNode);
        } else {
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addToHead(newNode);
            
            if (mp.size() > cap) {
                Node* toRemove = tail->prev;
                removeFromList(toRemove);
                mp.erase(toRemove->key);
                delete toRemove;
            }
        }
    }
    
private:
    void addToHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    void removeFromList(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Node* node) {
        removeFromList(node);
        addToHead(node);
    }
};
