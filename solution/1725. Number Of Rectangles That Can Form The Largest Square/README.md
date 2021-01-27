# 1725. Number Of Rectangles That Can Form The Largest Square

```cpp
int countGoodRectangles(vector<vector<int>>& rectangles) {
    int ans = 0, max_r = 0;
    for (auto& r : rectangles) {
        int cur = min(r[0], r[1]);
        if (max_r == cur) {
            ++ans;
        } else if (cur > max_r) {
            max_r = cur;
            ans = 1;
        }
    }
    return ans;
}
```
