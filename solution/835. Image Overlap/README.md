# 835. Image Overlap

The solution of 835_01.cpp and 835_02.cpp is wrong.

This solution covering only moving direction of right/down and left/up, not right/up and left/down. It passed because of there is not enough test cases on leetcode.

## 835_01.cpp

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        h = A.size(), w = A[0].size();
        
        int ans = 0;
        for (int offsetY = 0; offsetY < h; ++offsetY)
            for (int offsetX = 0; offsetX < w; ++offsetX)
                ans = max(ans, max(countOverlap(A, B, offsetY, offsetX),
                                   countOverlap(B, A, offsetY, offsetX)));
        
        return ans;
    }
    
private:
    int h, w;
    
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int offsetY, int offsetX) {
        int cnt = 0;
        for (int y = offsetY; y < h; ++y)
            for (int x = offsetX; x < w; ++x)
                cnt += A[y - offsetY][x - offsetX] * B[y][x];
        
        return cnt;
    }
};
```

## 835_02.cpp

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(shift_count(A, B), shift_count(B, A));
    }
    
private:
    int shift_count(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), count = 0;
        
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x) {
                int temp = 0;
                for (int i = y; i < n; ++i)
                    for (int j = x; j < n; ++j)
                        if (A[i][j] == 1 && B[i-y][j-x] == 1) temp++;
                count = max(count, temp);
            }
        
        return count;
    }
};
```

## 835_03.cpp

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), max_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                max_count = max(max_count, shift_count(A, B, i, j));
                max_count = max(max_count, shift_count(A, B, i, -j));
                max_count = max(max_count, shift_count(A, B, -i, j));
                max_count = max(max_count, shift_count(A, B, -i, -j));
            }
        }
        return max_count;
    }
    
private:
    int shift_count(vector<vector<int>>& A, vector<vector<int>>& B, int dirY, int dirX) {
        int n = A.size(), count = 0;
        
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x) {
                if (y + dirY < 0 || y + dirY >= n || x + dirX < 0 || x + dirX >= n)
                    continue;
                if (A[y][x] == 1 && B[y + dirY][x + dirX] == 1)
                    count++;
            }
        
        return count;
    }
};
```
