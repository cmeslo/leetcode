class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> preGreaterOrEqual(n, -1);
        vector<int> nextGreater(n, n);
        
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                preGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left <= nums[i] && nums[i] <= right) {
                int j =  preGreaterOrEqual[i], k = nextGreater[i];
                ans += (i - j) * (k - i);
            }
        }
        return ans;
    }
};
