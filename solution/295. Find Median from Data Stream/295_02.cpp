class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (l_.empty() || num < l_.top())
            l_.push(num);
        else
            r_.push(num);
        
        if (l_.size() - r_.size() == 2) {
            r_.push(l_.top());
            l_.pop();
        } else if (l_.size() < r_.size()) {
            l_.push(r_.top());
            r_.pop();
        }
    }
    
    double findMedian() {
        if (l_.size() > r_.size())
            return l_.top();
        else
            return (double) (l_.top() + r_.top()) / 2;
    }
    
private:
    priority_queue<int, vector<int>, less<>> l_;
    priority_queue<int, vector<int>, greater<>> r_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
