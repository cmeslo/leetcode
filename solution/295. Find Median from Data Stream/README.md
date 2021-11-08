# 295. Find Median from Data Stream

## Solution 1: multiset

使用 multiset 保存數字，再把 iterator 保持在中間。

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

## Solution 2: two heap

維護兩個數量平衡的 heap，

左邊使用 max heap，右邊使用 min heap。

```cpp
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
```
