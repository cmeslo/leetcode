class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN; // third 代表 nums[k]，是 i < j < k 時，比 nums[j] 小的下一個數字
        
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            
            int nums_j = nums[i];
            while (!st.empty() && nums_j > st.top()) { // stack 裡的元素都要比 nums[j] 大
                third = st.top(); // 被踢走的就是比 nums[j] 小的下一個數字
                st.pop();
            }
            
            st.push(nums_j);
        }
        
        return false;
    }
};
