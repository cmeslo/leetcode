# 341. Flatten Nested List Iterator

## Solution 1: 使用 stack (341_01.cpp)
每次遇到 List 時，都把 List 中的元素從後往前入棧。

```cpp
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            st_.push(nestedList[i]);
    }
    
    int next() {
        auto top = st_.top(); st_.pop();
        return top.getInteger();
    }
    
    bool hasNext() {
        while (!st_.empty()) {
            auto top = st_.top();
            if (top.isInteger())
                return true;
            
            st_.pop();
            auto list = top.getList(); 
            for (int i = list.size() - 1; i >= 0; --i)
                st_.push(list[i]);
        }
        return false;
    }
    
private:
    stack<NestedInteger> st_;
};
```

## Solution 2: 使用 deque (341_02.cpp)

使用雙向隊列也可以實現同樣效果，從隊列頭取元素，如果是list，再逐個放回隊列頭，直至第一個元素是integer。

```cpp
class NestedIterator {
private:
    deque<NestedInteger> dq;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger n : nestedList) dq.push_back(n);
    }

    int next() {
        NestedInteger n = dq.front();
        dq.pop_front();
        return n.getInteger();
    }

    bool hasNext() {
        while (!dq.empty()) {
            NestedInteger f = dq.front();
            if (f.isInteger()) {
                return true;
            } else {
                const vector<NestedInteger> &n = f.getList();
                dq.pop_front();
                for (int i = n.size() - 1; i >= 0; --i) dq.push_front(n[i]);
            }
        }
        return false;
    }
};
```
