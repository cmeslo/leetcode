# 295. Find Median from Data Stream

## Solution 1: multiset

把 iterator 保持在中間。

```cpp
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
```
