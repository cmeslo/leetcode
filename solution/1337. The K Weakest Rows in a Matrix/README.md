# 1337. The K Weakest Rows in a Matrix

## 解釋

維護大小為 k 的 max heap，

heap 裡保存的是，每一行 ```{1 的數目, 行數}```

- ```1 的數目```：除了可以用循環逐個數之外，還可以利用題目 <strong>all the 1's will appear to the left of all the 0's in each row</strong> 這個性質、做 binary search。

```cpp
// Your runtime beats 95.54 % of cpp submissions.
// Your memory usage beats 91.37 % of cpp submissions.

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            // int j = 0;
            // while (j < n && mat[i][j] != 0) ++j;
            int j = countSolider(mat[i]);
            q.emplace(j, i);
            if (q.size() > k) q.pop();
        }
        
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
    
private:
    int countSolider(vector<int>& row) {
        int l = 0, r = row.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (row[m] == 0)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
```
