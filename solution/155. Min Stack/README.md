# 155. Min Stack

## Solution 1: linked list

```cpp
class Node {
public:
    int val, mn;
    Node* next;
    
    Node(int val, int mn, Node* next): val(val), mn(mn), next(next) {}
};

class MinStack {
public:
    MinStack() {
        top_ = nullptr;
    }
    
    void push(int val) {
        if (!top_)
            top_ = new Node(val, val, nullptr);
        else
            top_ = new Node(val, min(val, top_->mn), top_);
    }
    
    void pop() {
        auto tmp = top_;
        top_ = top_->next;
        delete tmp;
    }
    
    int top() {
        return top_->val;
    }
    
    int getMin() {
        return top_->mn;
    }
    
private:
    Node* top_;
};
```
