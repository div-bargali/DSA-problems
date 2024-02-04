class DLL {
public:
    string url;
    DLL* next;
    DLL* prev;
  
    DLL() {
        this->url = "";
        this->next = nullptr; this->prev = nullptr; 
    }
    DLL(string URL) {
        this->url = URL;
        this->next = nullptr; this->prev = nullptr;
    }
};

class BrowserHistory {
private:
    DLL* head;
public:
    BrowserHistory(string homepage) {
        head = new DLL(homepage);
    }
    
    void visit(string url) {
        DLL* cur = new DLL(url);
        head->next = cur;
        cur->prev = head;
        head = cur;
    }
    
    string back(int steps) {
        if (!head) return nullptr;
        while(head->prev && steps > 0) {
            head = head->prev;
            steps--;
        }
        return head->url;
    }
    
    string forward(int steps) {
        if (!head) return nullptr;
        while (head->next && steps > 0) {
            head = head->next;
            steps--;
        }
        return head->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */