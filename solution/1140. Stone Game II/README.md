# 1140. Stone Game II

## Solution: DP

```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        suf.resize(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + piles[i];
        }
        return dp(piles, 0, 1);
    }
    
private:
    vector<int> suf;
    int cache[101][101];
    
    int dp(vector<int>& piles, int i, int M) {
        if (i >= piles.size()) return 0;
        if (cache[i][M] != 0)
            return cache[i][M];
        
        int res = 0, sum = 0;
        for (int x = 1; x <= 2 * M && i + x - 1 < piles.size(); ++x) {
            sum += piles[i + x - 1];
            res = max(res, sum + suf[i + x] - dp(piles, i + x, max(M, x)));
        }
        return cache[i][M] = res;
    }
};
```
