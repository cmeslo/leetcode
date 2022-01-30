class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nextSmaller(n, n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> prevSmallerOrEqual(n, -1);
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                prevSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> nextGreater(n, n);
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> prevGreaterOrEqual(n, -1);
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                prevGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += (long long)nums[i] * (i - prevGreaterOrEqual[i]) * (nextGreater[i] - i);
            res -= (long long)nums[i] * (i - prevSmallerOrEqual[i]) * (nextSmaller[i] - i);
        }
        return res;
    }
};

// sum of subarray ranges
// = sum of subarray maximum - sum of subarray minimum


// x x x x x x x
// l     i     r
// prevSmaller, nextSmaller


// tricky:
// 1 2 3 4 3 4 4
//             i
// prevSmallerOrEqual, nextSmall
