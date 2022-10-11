# 703. Kth Largest Element in a Stream

## Solution 1: multiset

### Example

```
8 5 4 2
3:  8  5 [4] 3 2
5:  8  5 [5] 4 3 2
10: 10 8 [5] 5 4 3 2
```

### Code

```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums)
            s.insert(x);
        
        it = next(s.begin(), k - 1);
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() == k || val > *it)
            it = prev(it);
        return *it;
    }
    
private:
    multiset<int, greater<>> s;
    multiset<int, greater<>>::iterator it;
    int k;
};
```
