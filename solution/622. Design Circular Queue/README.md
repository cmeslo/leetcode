# 622. Design Circular Queue

用 array 保存元素，再加上三個變量：頭指針、尾指針、隊列size。

```cpp
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q_.resize(k, -1);
        head_ = 0, tail_ = -1;
        size_ = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        ++size_;
        tail_ = (tail_ + 1) % q_.size();
        q_[tail_] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        --size_;
        head_ = (head_ + 1) % q_.size();
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q_[head_];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q_[tail_];
    }
    
    bool isEmpty() {
        return size_ == 0;
    }
    
    bool isFull() {
        return size_ == q_.size();
    }
    
private:
    vector<int> q_;
    int head_, tail_;
    int size_;
};
```
