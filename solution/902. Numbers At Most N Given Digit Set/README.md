# 902. Numbers At Most N Given Digit Set

## Solution 1: DFS (901.cpp)


最初以為是排列問題，無腦使用排列的方法做出來，但TLE了

```cpp
// TLE 的方法
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(begin(digits), end(digits));
        double cur = 0;
        int ans = 0;
        dfs(digits, n, cur, ans);
        return ans;
    }
    
private:
    void dfs(const vector<string>& digits, const int& n, double cur, int& ans) {
        if (cur > n) return;
        if (cur && cur <= n) ++ans;
        
        for (string d : digits) {
            double tmp = cur * 10 + stoi(d);
            if (tmp > n) break;
            dfs(digits, n, tmp, ans);
        }
    }
};
```

實際上，有很大一部分數字是可以通過計算得到，所以優化如下：

```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        long res = 0, cur = 1;
        for (int i = 0; i < N.size() - 1; ++i) {
            cur *= digits.size();
            res += cur;
        }
        return res + dfs(N, digits, 0);
    }
    
    long dfs(const string& N, vector<string>& digits, int start) {
        if (start >= N.size()) return 1;
        int res = 0;
        int i = 0;
        for (; i < digits.size() && digits[i][0] < N[start]; ++i) {
            res += pow(digits.size(), N.size() - start - 1);
        }
        if (i < digits.size() && digits[i][0] == N[start]) {
            res += dfs(N, digits, start + 1);
        }
        return res;
    }
};
```

## Solution 2 : DP (902.cpp)

```cpp
int atMostNGivenDigitSet(vector<string>& digits, int N) {
    const string s = to_string(N);
    const int n = s.length();
    const int D = digits.size();
    int ans = 0;

    for (int i = 1; i < n; ++i)
        ans += pow(D, i);

    for (int i = 0; i < n; ++i) {
        bool prefix = false;
        for (const string& d : digits) {
            if (d[0] < s[i]) {
                ans += pow(D, n - i - 1);
            } else if (d[0] == s[i]) { // 因為 digits 的長度最多只有9，不判斷 > 退出也可以、沒有太大影響
                prefix = true;
                break;
            }
        }
        if (prefix == false) return ans;
    }

    return ans + 1;
}
```

or

```cpp
int atMostNGivenDigitSet(vector<string>& digits, int N) {
    const string s = to_string(N);
    const int n = s.length();
    const int D = digits.size();
    int ans = 0;

    for (int i = 1; i < n; ++i)
        ans += pow(D, n - i); // *

    for (int i = 0; i < n; ++i) {
        bool prefix = false;
        for (const string& d : digits) {
            if (d[0] < s[i]) {
                ans += pow(D, n - i - 1);
            } else if (d[0] >= s[i]) { // * 判斷 > 直接退出
                if (d[0] == s[i]) prefix = true;
                break;
            }
        }
        if (prefix == false) return ans;
    }

    return ans + 1;
}
```

reference: https://zxi.mytechroad.com/blog/math/leetcode-902-numbers-at-most-n-given-digit-set/
