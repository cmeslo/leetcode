class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // if (n < 3) return false;
        
        vector<int> mins(n);
        mins[0] = nums[0];
        for (int i = 1; i < n; ++i)
            mins[i] = min(mins[i - 1], nums[i]);
        
        stack<int> st;
        for (int j = n - 1; j >= 0; --j) {
            int nums_i = mins[j];
            while (!st.empty() && nums_i >= st.top())
                st.pop();
            
            if (!st.empty() && nums[j] > st.top())
                return true;
            
            st.push(nums[j]);
        }
        
        return false;
    }
};
