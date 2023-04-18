# 1239. Maximum Length of a Concatenated String with Unique Characters

## Solution 1: Backtracking

### 寫法一：

```cpp
// Runtime: 20 ms, Your runtime beats 73.11 % of cpp submissions.
// Your memory usage beats 57.07 % of cpp submissions.

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<int, int>> A; // {code, len}
        for (string& x : arr) {
            int code = 0;
            for (char& c : x) {
                int pos = 1 << (c - 'a');
                if ((code & pos) != 0) { // 如果自己本身已經有重複，則不考慮
                    code = 0;
                    break;
                }
                code |= pos;
            }
            if (code) A.push_back({code, x.length()});
        }
        
        int ans = 0;
        dfs(A, 0, 0, 0, ans);
        return ans;
    }
    
private:
    void dfs(vector<pair<int, int>> A, int start, int cur, int len, int& ans) {
        ans = max(ans, len);
        for (int i = start; i < A.size(); ++i) {
            if ((cur & A[i].first) == 0)
                dfs(A, i + 1, cur | A[i].first, len + A[i].second, ans);
        }
    }
};
```

or

```cpp
// Runtime: 7 ms, Your runtime beats 86.81 % of cpp submissions.
// Memory Usage: 8.2 MB, Your memory usage beats 93.70 % of cpp submissions.

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> A;
        for (string w : arr) {
            int b = 0;
            for (char& c : w)
                b |= 1 << (c - 'a');
            if (__builtin_popcount(b) == w.size())
                A.push_back(b);
        }
        
        int res = 0;
        dfs(A, 0, 0, res);
        return res;
    }
    
    void dfs(vector<int>& A, int i, int state, int& res) {
        res = max(res, __builtin_popcount(state));
        
        for (int j = i; j < A.size(); ++j) {
            if (state & A[j]) continue;
            dfs(A, j + 1, state | A[j], res);
        }
    }
};
```

### 寫法二：

不預先計算反而比較快：

```cpp
// Runtime: 4 ms, Your runtime beats 95.12 % of cpp submissions.
// Your memory usage beats 98.21 % of cpp submissions.

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        dfs(arr, 0, 0, 0, ans);
        return ans;
    }
    
private:
    void dfs(vector<string>& arr, int start, int curMask, int len, int& ans) {
        ans = max(ans, len);
        for (int i = start; i < arr.size(); ++i) {
            int mask = concat(curMask, arr[i]);
            if (mask != -1)
                dfs(arr, i + 1, mask, len + arr[i].length(), ans);
        }
    }
    
    int concat(int mask, const string& str) {
        for (const char& c : str) {
            int pos = 1 << (c - 'a');
            if ((mask & pos) != 0) return -1;
            mask |= pos;
        }
        return mask;
    }
};
```

## Solution 2: Bit Manipulation

```cpp
// Runtime: 32 ms, Your runtime beats 68.63 % of cpp submissions.
// Your memory usage beats 92.43 % of cpp submissions.

int maxLength(vector<string>& arr) {
    int n = arr.size();
    vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        int b = 0;
        for (char& c : arr[i]) {
            if ((b >> (c - 'a')) & 1) {
                b = INT_MAX;
                break;
            }
            b |= (1 << (c - 'a'));
        }
        B[i] = b;
    }

    int ans = 0;
    for (int state = 0; state < (1 << n); ++state) {
        int cur = 0;
        for (int i = 0; i < 26; ++i) {
            if ((state >> i) & 1) {
                if (cur & B[i]) {
                    cur = 0;
                    break;
                }
                cur |= B[i];
            }
        }
        if (cur != INT_MAX)
            ans = max(ans, __builtin_popcount(cur));
    }
    return ans;
}
```
