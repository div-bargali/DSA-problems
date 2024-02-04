class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int num = peek();
        output.pop();
        return num;
    }
    
    int peek() {
        if (output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int num = output.top();
        return num;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */