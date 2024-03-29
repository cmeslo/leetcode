# 1423. Maximum Points You Can Obtain from Cards

## Solution 1: Sliding Window

```cpp
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    if (n == k) return total;
    int size = n - k;

    int ans = 0, sum = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        sum += cardPoints[j];
        if (j - i + 1 == size) {
            ans = max(ans, total - sum);
            sum -= cardPoints[i++];
        }
    }
    return ans;
}
```

or

```cpp
int maxScore(vector<int>& p, int k) {
    int n = p.size();
    int total = accumulate(begin(p), end(p), 0);
    int cur = 0;
    for (int i = 0; i < n - k; ++i)
        cur += p[i];

    int mn = cur;
    for (int i = n - k; i < n; ++i) {
        cur = cur - p[i - (n - k)] + p[i];
        mn = min(cur, mn);
    }
    return total - mn;
}
```

## Solution 2: Better Sliding Window

```
[1,2,3],4,5,6,1,     k = 3
1,2],3,4,5,6,[1,     k = 3
1],2,3,4,5,[6,1,     k = 3
1,2,3,4,[5,6,1],     k = 3
```

```cpp
int maxScore(vector<int>& p, int k) {
    int n = p.size();
    int cur = accumulate(begin(p), begin(p) + k, 0);
    int ans = cur;
    for (int i = 0; i < k; ++i) {
        cur = cur - p[k - i - 1] + p[n - i - 1];
        ans = max(ans, cur);
    }
    return ans;
}
```
