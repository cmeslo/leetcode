class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -2;
        int mn = INT_MAX, mx = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            if (mx > nums[i])
                r = i;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            mn = min(mn, nums[i]);
            if (mn < nums[i])
                l = i;
        }
        
        return r - l + 1;
    }
};

// 這種做法與 stack 的原理其實是一樣的:

// 我用 正向遞增 monotnoic stack 是找到第一個不合理的位置 i
// 這個不合理的 i 其實就是指: 在這個 i 後面存在一個比 nums[i] 更小的數字
// 尋找時要由後向前找

// 我用 反向遞減 monotnoic stack 是找到最後一個不合理的位置 i
// 這個不合理的 i 其實就是指: 在這個 i 前面存在一個比 nums[i] 更大的數字
// 尋找時要由前向後找
