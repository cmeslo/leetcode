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
