# 315. Count of Smaller Numbers After Self

## Solution: FenwickTree + offset

```cpp
// Your runtime beats 95.12 % of cpp submissions.
// Your memory usage beats 91.70 % of cpp submissions.

class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1) {};
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    
    vector<int> sums_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        auto minmax = minmax_element(nums.begin(), nums.end());
        int mn = *minmax.first;
        int mx = *minmax.second;
        
        vector<int> ans(n);
        FenwickTree tree(mx + abs(mn));
        int offset = abs(mn) + 1; // make it positive
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = tree.query(nums[i] + offset - 1);
            tree.update(nums[i] + offset, 1);
        }
        return ans;
    }
};
```
