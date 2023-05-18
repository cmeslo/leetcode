# 901. Online Stock Span

```cpp
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.emplace(price, res);
        return res;
    }
    
private:
    stack<pair<int, int>> st; // price, span
};
```
