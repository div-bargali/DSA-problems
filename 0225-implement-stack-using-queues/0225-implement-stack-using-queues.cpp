class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        // take the first n-1 elements, and pop them and push them again to back of the queue
        // this way order is FIFO only, but last-inserted element is at first
        q.push(x);
        int n = q.size();
        for(int i = 0; i < n-1; i++) {
            int num = q.front(); q.pop();
            q.push(num);
        }
    }
    
    int pop() {
        int num = top();
        q.pop();
        return num;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */