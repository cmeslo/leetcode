class FreqStack {
private:
    unordered_map<int, int> freq_;
    vector<stack<int>> stacks_;
    
public:
    FreqStack() {
    }
    
    void push(int val) {
        auto it = freq_.find(val);
        if (it == freq_.end())
            it = freq_.emplace(val, 0).first;
        
        int freq = ++it->second;
        if (freq > stacks_.size())
            stacks_.push_back({});
        
        stacks_[freq - 1].push(val);
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
