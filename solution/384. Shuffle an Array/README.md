# 384. Shuffle an Array

## Solution (C++ version)

```cpp
class Solution {
public:
    Solution(vector<int>& nums) {
        A_ = nums;
    }
    
    vector<int> reset() {
        return A_;
    }
    
    vector<int> shuffle() {
        int n = A_.size();
        vector<int> res = A_;
        for (int i = 0; i < n; ++i) {
            int j = rand() % (n - i) + i;
            swap(res[i], res[j]);
        }
        return res;
    }
    
private:
    vector<int> A_;
};
```

shuffle 也可以反向：

```cpp
vector<int> shuffle() {
    vector<int> ans = A_;

    for (int i = A_.size() - 1; i >= 0; --i) {
        int j = rand() % (i + 1);
        swap(ans[i], ans[j]);
    }

    return ans;
}
```

## Solution (Java version)

```cpp
class Solution {
    private int[] nums;
    
    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    public int[] reset() {
        return nums;
    }
    
    public int[] shuffle() {
        int[] res = nums.clone();
        for (int i = 0; i < nums.length; ++i) {
            int rand = (int)(Math.random() * (nums.length - i)) + i;
            swap(res, i, rand);
        }
        return res;
    }
    
    private void swap(int[] res, int i, int j) {
        int tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
}
```
