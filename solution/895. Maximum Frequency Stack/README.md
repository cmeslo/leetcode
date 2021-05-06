# 895. Maximum Frequency Stack

## Solution 1 - priority_queue

```cpp
class FreqStack {
public:
    FreqStack() {
        seq = 0;
    }
    
    void push(int x) {
        arr.push_back(x);
        ++freq[x];
        q.emplace(freq[x], seq++);
    }
    
    int pop() {
        auto [f, i] = q.top(); q.pop();
        if (--freq[arr[i]] == 0)
            freq.erase(arr[i]);
        return arr[i];
    }
    
private:
    int seq;
    vector<int> arr;
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> q; // freq, seq
    
};
```

or

```cpp
class FreqStack {
public:
    FreqStack() {
        seq_ = 0;
    }
    
    void push(int val) {
        q_.push({++f_[val], seq_++, val});
    }
    
    int pop() {
        auto top = q_.top(); q_.pop();
        if (--f_[top[2]] == 0)
            f_.erase(top[2]);
        return top[2];
    }
    
private:
    priority_queue<vector<int>> q_; // 佔用很多空間，vector<int> 可以換成 pair<int, pair<int, int>>
    unordered_map<int, int> f_;
    int seq_;
};
```

## Solution 2 - stack

```cpp
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
```
