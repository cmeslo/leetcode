class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s_.insert(num);
        
        if (s_.size() == 1) {
            it = s_.begin();
            result = *it;
            return;
        }
        
        if (s_.size() % 2) {
            if (*it <= num)
                it = next(it);
            result = *it;
        } else {
            if (num < *it)
                it = prev(it);
            result = *it * 0.5 + *next(it) * 0.5;
        }
    }
    
    double findMedian() {
        return result;
    }
    
private:
    multiset<int> s_;
    multiset<int>::iterator it;
    double result = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
