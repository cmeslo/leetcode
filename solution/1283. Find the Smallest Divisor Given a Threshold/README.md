# 1283. Find the Smallest Divisor Given a Threshold

1. 看清楚這題本質是二分查找，因為 sum 會隨着 divisor 改變呈現出單調性，```divisor 越大，sum 越小```、```divisor 越小，sum 越大```。

2. 另外要注意 向上取整的除法，比如 n / d ，有以下三種寫法：

```
(n - 1)/d + 1
(n + (d - 1)) / d
n / d + (n % d == 0 ? 0 : 1)
```

```(n + (d - 1)) / d``` 可以這樣理解：因為 ceil(n) = int(n + 0.999), 所以加上一個很大的float數字 (d-1)/d

## 1283.cpp

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(begin(nums), end(nums)); // 或者 r = 1e6
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (sum_division(nums, mid) <= threshold)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    
private:
    int sum_division(const vector<int>& nums, int d) {
        int sum = 0;
        for (int n : nums)
            sum += (n + (d - 1)) / d;
        return sum;
    }
};
```
