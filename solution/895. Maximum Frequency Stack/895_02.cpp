class FreqStack {
private:
    vector<stack<int>> stacks_;
    unordered_map<int, int> freq_;
    
public:
    FreqStack() {
    }
    
    void push(int val) {
        int count = ++freq_[val];
        
        if (count > stacks_.size())
            stacks_.push_back({});
        
        stacks_[count - 1].push(val);
    }
    
    int pop() {
        int val = stacks_.back().top();
        stacks_.back().pop();
        
        if (stacks_.back().empty())
            stacks_.pop_back();
        
        if (--freq_[val] == 0)
            freq_.erase(val);
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
