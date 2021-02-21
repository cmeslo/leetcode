class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        H.insert(begin(H), 0);
        H.push_back(0);
        stack<int> st;
        st.push(0);
        
        int ans = 0;
        for (int i = 1; i < H.size(); ++i) {
            while (H[st.top()] > H[i]) {
                int h = H[st.top()]; st.pop();
                int w = i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
};
