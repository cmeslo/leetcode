# 312. Burst Balloons

## 解釋：

最先入為主的想法是，每打破一個氣球，就把該氣球從數組中移除掉，遞歸地計算下一層，最後再補回該元素，然後打下一個氣球，

但這明顯行不通，每次數組元素的移除和添加都要O(n)的時間。

反過來想，每次迭代，要找<strong>最後一個</strong>打破的氣球 k

```
1 l . . . . . r 1
^---------------^--------先往兩邊添加 1，方便計算
1 k . . . . . r 1
  ^----------------------最後才打破它
1 l k . . . . r 1
    ^--------------------最後才打破它
1 l . k . . . r 1
      ^------------------最後才打破它
...
...
1 l . . . . . k 1
              ^----------最後才打破它

可以得到公式：

dp[l][r] = max(dp[l][r], nums[l-1] * nums[k] * nums[r+1] + dp[l][k-1] + dp[l][k-1] + dp[k+1][r])
```

### Bottom up - DP

要知道 dp[l][r]，要先知道dp[l][k-1]和dp[k+1][r]，所以bottom up要由len小至大

```
base case:
if (l > r) return 0
if (l == r) return nums[l-1] * nums[l] * nums[l+1]
```

#### Code

```cpp
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int k = l; k <= r; ++k)
                dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r] + nums[l-1] * nums[k] * nums[r+1]);
        }
    }

    return dp[1][n];
}
```

### Top down - Recursive

#### Code

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
        return dp(nums, 1, n, mem);
    }
    
private:
    int dp(vector<int>& nums, int l, int r, vector<vector<int>>& mem) {
        if (l > r) return 0;
        if (mem[l][r] != -1) return mem[l][r];
        if (l == r) return mem[l][r] = nums[l - 1] * nums[l] * nums[l + 1];
        for (int i = l; i <= r; ++i) {
            int sum = nums[l - 1] * nums[i] * nums[r + 1] + dp(nums, l, i - 1, mem) + dp(nums, i + 1, r, mem);
            mem[l][r] = max(mem[l][r], sum);
        }
        return mem[l][r];
    }
};
```

or

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return burst(nums, 0, n - 1, mem);
    }
    
private:
    int burst(vector<int>& nums, int l, int r, vector<vector<int>>& mem) {
        if (l + 1 == r) return 0;
        if (mem[l][r] != -1) return mem[l][r];
        
        for (int k = l + 1; k < r; ++k) {
            int sum = nums[l] * nums[k] * nums[r] + burst(nums, l, k, mem) + burst(nums, k, r, mem);
            mem[l][r] = max(mem[l][r], sum);
        }
        return mem[l][r];
    }
};
```
