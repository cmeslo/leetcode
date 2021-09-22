# 307. Range Sum Query - Mutable

## Solution: Fenwick Tree (Binary Indexed Tree)

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        nums_.resize(n, 0);
        sums_.resize(n + 1, 0);
        for (int i = 0; i < n; ++i)
            update(i, nums[i]);
        nums_ = std::move(nums);
    }
    
    void update(int index, int val) {
        int i = index + 1;
        int delta = val - nums_[index];
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefix(right + 1) - prefix(left);
    }
    
private:
    vector<int> nums_;
    vector<int> sums_;

    static inline int lowbit(int x) {
        return x & (-x);
    }
    
    int prefix(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
};
```
