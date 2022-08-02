# 875. Koko Eating Bananas

## Solution: Binary Search

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isOK(piles, h, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    
private:
    bool isOK(vector<int>& P, int h, int m) {
        for (int x : P) {
            h -= (x + m - 1) / m;
            if (h < 0) return false;
        }
        return true;
    }
};
```
