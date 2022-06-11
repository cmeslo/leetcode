# 85. Maximal Rectangle

## Solution 1: Brute force (85_01.cpp)

Base on **84. Largest Rectangle in Histogram**

## Solution 2: Monotonic stack (85_02.cpp)

Base on **84. Largest Rectangle in Histogram**

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

## Solution 3: DP (85_03.cpp)

nice dp solution

[reference](https://discuss.leetcode.com/topic/6650/share-my-dp-solution).

