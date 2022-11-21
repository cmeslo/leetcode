# 225. Implement Stack using Queues

```cpp
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = q.size(); i > 1; --i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front(); q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};
```
