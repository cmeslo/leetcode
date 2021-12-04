# 932. Beautiful Array

```cpp
class Solution {
public:
    vector<int> beautifulArray(int n) {
        memo_[1] = {1};
        return f(n);
    }
    
private:
    unordered_map<int, vector<int>> memo_;
    
    vector<int> f(int n) {
        if (memo_.count(n)) return memo_[n];
        
        vector<int> ans(n);
        int i = 0;
        for (int x : f((n + 1) / 2)) {
            ans[i++] = 2 * x - 1;
        }
        for (int x : f(n / 2)) {
            ans[i++] = 2 * x;
        }
        
        return memo_[n] = ans;
    }
};

// n = 1: {1}
// n = 2: {1,2}
// n = 3: {1,3,2}
// n = 4: {1,3,2,4}
// n = 5: {1,5,3,2,4}
```
