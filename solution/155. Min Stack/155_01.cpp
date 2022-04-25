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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
