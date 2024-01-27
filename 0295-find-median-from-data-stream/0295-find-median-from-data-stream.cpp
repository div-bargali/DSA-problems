class MedianFinder {
private:
    priority_queue<int> maxH; // to store smaller half of nums
    priority_queue<int, vector<int>, greater<int>> minH; // to store larger half of nums

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // follow 2 rules only - 
        // 1. size diff b/w maxH and minH should be not more than 1
        // 2. elements in maxH should be <= elements in minH
        maxH.push(num);
        if (maxH.size() - minH.size() > 1 ) {
            // 1. if size diff is more than 1, we have to balance the heaps
            // then take the element and place it in larger half
            int elem = maxH.top(); maxH.pop();
            minH.push(elem);
        } if ((!minH.empty() && maxH.top() > minH.top())) {
            // 2. if largest in smaller half is greater than smallest in larger half
            // then swap the 2 elements
            int elem = maxH.top(); maxH.pop();
            maxH.push(minH.top()); minH.pop();
            minH.push(elem);
        } 
        
    }
    
    double findMedian() {
        if (maxH.size() > minH.size()) {
            // odd # of elements -> median is in smaller half -> so top element of maxH
            return maxH.top();
        } else if (minH.size() > maxH.size()) {
            // odd # of elements -> median is in larger half -> so top element of minH
            return minH.top();
        } else {
            // even # of elements -> take mean of the middle 2 -> largest in smaller and smallest in larger half
            return (maxH.top() + minH.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */