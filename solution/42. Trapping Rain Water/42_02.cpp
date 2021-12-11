class Solution {
public:
    int trap(vector<int>& H) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < H.size(); ++i) {
            while (!st.empty() && H[st.top()] < H[i]) {
                int base = H[st.top()]; st.pop();
                if (st.empty()) break;
                int h = min(H[st.top()], H[i]) - base;
                int w = i - st.top() - 1;
                res += h * w;
            }
            st.push(i);
        }
        return res;
    }
};
