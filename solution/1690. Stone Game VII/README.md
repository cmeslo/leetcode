# 1690. Stone Game VII

## Solution 1: Recursion + memo

```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int sum = accumulate(begin(stones), end(stones), 0);
        int n = stones.size();
        mem_alice.clear();
        mem_alice.resize(n, vector<int>(n, -1));
        mem_bob.clear();
        mem_bob.resize(n, vector<int>(n, -1));
        return take(stones, 0, n - 1, sum, true);
    }
    
private:
    vector<vector<int>> mem_alice;
    vector<vector<int>> mem_bob;
    
    int take(vector<int>& stones, int l, int r, int sum, bool alice_turn) {
        if (l == r) return 0;
        
        int sum1 = sum - stones[l];
        int sum2 = sum - stones[r];
        
        if (alice_turn) {
            if (mem_alice[l][r] != -1) return mem_alice[l][r];
            int choice1 = sum1 + take(stones, l + 1, r, sum1, !alice_turn);
            int choice2 = sum2 + take(stones, l, r - 1, sum2, !alice_turn);
            return mem_alice[l][r] = max(choice1, choice2);
        } else {
            if (mem_bob[l][r] != -1) return mem_bob[l][r];
            int choice1 = -sum1 + take(stones, l + 1, r, sum1, !alice_turn);
            int choice2 = -sum2 + take(stones, l, r - 1, sum2, !alice_turn);
            return mem_bob[l][r] = min(choice1, choice2);
        }
    }
};
```
