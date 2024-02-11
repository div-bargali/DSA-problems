class StockSpanner {
    stack<pair<int, int>> stk; // pair: (price, span)
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        
        // Pop elements from the stack while the stack is not empty and the price at the current index is greater than or equal to the price at the top of the stack
        while (!stk.empty() && price >= stk.top().first) {
            span += stk.top().second; // Add the span of the top element to the current span
            stk.pop(); // Pop the top element
        }
        
        // Push the current price and its span onto the stack
        stk.push({price, span});
        
        return span;
    }
};

// Example usage:
// StockSpanner* obj = new StockSpanner();
// int param_1 = obj->next(price);
