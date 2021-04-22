# 11. Container With Most Water

## Solution: Two Pointers

```cpp
int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;

    int ans = 0;
    while (l < r) {
        int w = r - l;
        int h = min(height[l], height[r]);
        ans = max(ans, w * h);
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return ans;
}
```
