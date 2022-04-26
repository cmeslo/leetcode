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

## Solution 2: Two stacks

### 寫法一：

用兩個 stack，以下是 stack2 的元素比 stack1 少的寫法

```cpp
class MinStack {
public:
    stack<int> st1, st2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if (st2.empty() || st2.top() >= val)
            st2.push(val);
    }
    
    void pop() {
        if (st2.top() == st1.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
```

### 寫法二：

也可以直接讓 stack1, stack2 元素數量一樣多，更簡潔

```cpp
st1.push(val)
st2.push(min(st2.top(), val))
```
