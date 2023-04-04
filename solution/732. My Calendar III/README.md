# 732. My Calendar III

## Solution

```cpp
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        s.insert({start, 1});
        s.insert({end, -1});
        
        int res = 0, count = 0;
        for (auto& x : s) {
            count += x.second;
            res = max(res, count);
        }
        return res;
    }
    
private:
    multiset<pair<int, int>> s;
};
```
