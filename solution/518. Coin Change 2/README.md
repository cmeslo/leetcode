# Time Limit Exceeded 的解法

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        _res = 0;
        backtrack(amount, coins, 0);
        return _res;
    }
    
private:
    int _res;
    
    void backtrack(int amount, const vector<int>& coins, int start) {
        if (amount < 0) return;
        if (amount == 0) {
            _res += 1;
            return;
        }
        for (int i = start; i < coins.size(); i++) {
            backtrack(amount-coins[i], coins, i);
        }
    }
};
```
