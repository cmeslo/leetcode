class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int n = arr.size(), MOD = 1e9 + 7;
        
        vector<int> nextSmaller(n, n), prevSmallerOrEqual(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                prevSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long res = 0;
        for (int i = 0; i < n; ++i)
            res = (res + 1L * (i - prevSmallerOrEqual[i]) * (nextSmaller[i] - i) * arr[i]) % MOD;
        return res;
    }
};

// 1 1 . . . 4 . . . 4 2
// a         i       b
