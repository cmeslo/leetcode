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

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
