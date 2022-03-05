# 978. Longest Turbulent Subarray

## Solution: DP

```python
if arr[i-1] < arr[i]
    dp_up[i] = dp_down[i-1] + 1;
    dp_down[i] = 1;
if (arr[i-1] > arr[i])
    dp_down[i] = dp_up[i-1] + 1;
    dp_up[i] = 1
if (arr[i-1] == arr[i])
    dp_up[i] = dp_down[i] = 1;

      1 2 1 2 1 2
up:   1 2 1 4 1 6 <-- ans = 6
down: 1 1 3 1 5 1

      9 4 2 10 7 8 8 1 9
up:   1 1 1 3  1 5 1 1 3 <-- ans = 5
down: 1 2 2 1  4 1 1 2 1

      2 0 2 4 2 5 0 1 2 3
up:   1 1 3 2 1 4 1 6 2 2  <-- ans = 6
down: 1 2 1 1 3 1 5 1 1 1
```

### Code

```cpp
int ans = 1, up = 1, down = 1;
for (int i = 1; i < arr.size(); ++i) {
    if (arr[i - 1] < arr[i]) {
        up = down + 1;
        down = 1;
    } else if (arr[i - 1] > arr[i]) {
        down = up + 1;
        up = 1;
    } else {
        up = down = 1;
    }
    ans = max(ans, max(up, down));
}
return ans;
```
