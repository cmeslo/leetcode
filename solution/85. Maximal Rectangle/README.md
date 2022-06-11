# 85. Maximal Rectangle

## Solution 1: Brute force (85_01.cpp)

Base on **84. Largest Rectangle in Histogram**

## Solution 2: Monotonic stack (85_02.cpp)

Base on **84. Largest Rectangle in Histogram**

### C++

32 ms, Your runtime beats 99.40 % of cpp submissions.

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        int res = 0;
        vector<int> row(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[j] = matrix[i][j] == '0' ? 0 : row[j] + 1;
            }
            res = max(res, maxHistogram(row));
        }
        return res;
    }
    
private:
    int maxHistogram(vector<int> H) {
        H.insert(H.begin(), 0);
        H.push_back(0);
        stack<int> st({0});
        int area = 0;
        for (int i = 1; i < H.size(); ++i) {
            while (H[st.top()] > H[i]) {
                int h = H[st.top()]; st.pop();
                int w = i - st.top() - 1;
                area = max(area, h * w);
            }
            st.push(i);
        }
        return area;
    }
};
```

or

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> row(n + 2, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[j + 1] = matrix[i][j] == '0' ? 0 : row[j + 1] + 1;
            }
            ans = max(ans, maxHistogram(row));
        }
        return ans;
    }
    
private:
    int maxHistogram(vector<int>& H) {
        int area = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < H.size(); ++i) {
            while (H[st.top()] > H[i]) {
                int h = H[st.top()]; st.pop();
                int w = i - st.top() - 1;
                area = max(area, h * w);
            }
            st.push(i);
        }
        return area;
    }
};
```

### Java

```java
// 4 ms, Your runtime beats 96.76 % of java submissions.

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int[] H = new int[n + 2];
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                H[j + 1] = matrix[i][j] == '0' ? 0 : H[j + 1] + 1;
            }
            res = Math.max(res, getMaxArea(H));
        }
        return res;
    }
    
    private int getMaxArea(int[] H) {
        int area = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.addLast(0);
        for (int i = 1; i < H.length; ++i) {
            while (H[stack.peekLast()] > H[i]) {
                int h = H[stack.pollLast()];
                int w = i - stack.peekLast() - 1;
                area = Math.max(area, h * w);
            }
            stack.addLast(i);
        }
        return area;
    }
}
```

## Solution 3: DP (85_03.cpp)

nice dp solution

[reference](https://discuss.leetcode.com/topic/6650/share-my-dp-solution).

