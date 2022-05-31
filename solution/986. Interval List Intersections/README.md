# 986. Interval List Intersections

## Solution: Two pointers

### C++

```cpp
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        int start = max(A[i][0], B[j][0]);
        int end = min(A[i][1], B[j][1]);
        if (start <= end) {
            res.push_back({start, end});
        }
        if (A[i][1] < B[j][1])
            ++i;
        else
            ++j;
    }
    return res;
}
```

### Java

```java
public int[][] intervalIntersection(int[][] A, int[][] B) {
    ArrayList<int[]> res = new ArrayList<int[]>();
    int i = 0, j = 0;
    while (i < A.length && j < B.length) {
        int start = Math.max(A[i][0], B[j][0]);
        int end = Math.min(A[i][1], B[j][1]);
        if (start <= end)
            res.add(new int[]{start, end});
        if (A[i][1] < B[j][1])
            ++i;
        else
            ++j;
    }
    return res.toArray(new int[res.size()][2]);
}
```
