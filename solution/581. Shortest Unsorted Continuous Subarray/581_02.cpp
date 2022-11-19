class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n, r = -1;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        if (st.size() == n) return 0;
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return r - l + 1;
    }
};
