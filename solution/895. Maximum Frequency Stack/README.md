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
