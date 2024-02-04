# 920. Number of Music Playlists

# Solution 1: DP

## C++
```cpp
int numMusicPlaylists(int n, int goal, int k) {
    const int M = 1e9 + 7;
    vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
    dp[1][1] = n;

    for (int i = 2; i <= goal; ++i) {
        for (int j = 1; j <= min(i, n); ++j) {
            if (i > k)
                dp[i][j] += dp[i - 1][j] * (j - k);
            if (n > j - 1)
                dp[i][j] += dp[i - 1][j - 1] * (n - j + 1);
            dp[i][j] %= M;
        }
    }

    return dp[goal][n];
}
```

# Solution 2: DFS

## Python

### 寫法一: 使用 dict 作為 memorizaton

```py
def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
    mod = 10**9 + 7
    dp = {}

    def count(cur_goal, old_songs):
        if cur_goal == 0 and old_songs == n:
            return 1
        if cur_goal == 0 or old_songs > n:
            return 0
        if (cur_goal, old_songs) in dp:
            return dp[(cur_goal, old_songs)]

        # choose new song
        res = (n - old_songs) * count(cur_goal - 1, old_songs + 1)

        # choose old song
        if old_songs > k:
            res += (old_songs - k) * count(cur_goal - 1, old_songs)

        dp[(cur_goal, old_songs)] = res % mod
        return dp[(cur_goal, old_songs)]

    return count(goal, 0)
```

### 寫法二: 使用 ```@lru_cache(None)``` 作為 memorizaton

```py
def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
    mod = 10**9 + 7

    @lru_cache(None)
    def count(cur_goal, old_songs):
        if cur_goal == 0 and old_songs == n:
            return 1
        if cur_goal == 0 or old_songs > n:
            return 0

        # choose new song
        res = (n - old_songs) * count(cur_goal - 1, old_songs + 1)

        # choose old song
        if old_songs > k:
            res += (old_songs - k) * count(cur_goal - 1, old_songs)
        
        return res % mod

    return count(goal, 0)
```
