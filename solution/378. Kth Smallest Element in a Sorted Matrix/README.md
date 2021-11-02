# 378. Kth Smallest Element in a Sorted Matrix

## Solution 1: heap

```cpp
// Your runtime beats 12.78 % of cpp submissions.
// Your memory usage beats 59.28 % of cpp submissions.

typedef pair<int, int> PII;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        auto cmp = [&](PII& a, PII& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        pq.emplace(0, 0);
        
        while (--k) {
            auto [y, x] = pq.top(); pq.pop();
            if (y + 1 < m && !visited[y + 1][x]) {
                visited[y + 1][x] = true;
                pq.emplace(y + 1, x);
            }
            if (x + 1 < n && !visited[y][x + 1]) {
                visited[y][x + 1] = true;
                pq.emplace(y, x + 1);
            }
        }
        
        return matrix[pq.top().first][pq.top().second];
    }
};
```

## Solution 2: Binary Search

```cpp
// Your runtime beats 99.09 % of cpp submissions.
// Your memory usage beats 93.31 % of cpp submissions.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countSmallerOrEqual(matrix, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    
private:
    int countSmallerOrEqual(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int y = n - 1, x = 0;
        int cnt = 0;
        while (y >= 0 && x < n) {
            if (matrix[y][x] <= val) {
                cnt += y + 1;
                ++x;
            } else {
                --y;
            }
        }
        return cnt;
    }
};
```
