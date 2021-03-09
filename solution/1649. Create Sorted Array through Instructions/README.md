# 1649. Create Sorted Array through Instructions

## FenwickTree / Binary Indexed Tree

Fenwick Tree 就是動態的 prefix sum，每次有元素修改後，都保證可以在 logN 的時間內計算出新結果。

而這一題，每次插入元素，都要知道前面比我小的有多少個數字（左面）、比我大的有多少個數字（右面），所以適合用 Fenwick Tree，

每遇到一個數字、FenwickTree 裡的節點對應 +1，然後我就可以快速知道 i 前面出現過多少個數字，

最後每次看看左面有多少個數字、右面有多少個數字。

### 1649.cpp
```cpp
class FenwickTree {
public:
    FenwickTree(int n): sum_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sum_.size()) {
            sum_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sum_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    vector<int> sum_;
    
    static inline int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        FenwickTree tree(1e5);
        long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int lt = tree.query(instructions[i] - 1);
            int gt = i - tree.query(instructions[i]);
            ans += min(lt, gt);
            tree.update(instructions[i], 1);
        }
        return ans % 1000000007;
    }
};
```

其中：
```cpp
// 比 instructions[i] 小的有多少個
int lt = tree.query(instructions[i] - 1);

// i 相當於目前有多少個 1，
// i - tree.query(instructions[i]) 相當於比 instructions[i] 大的有多少個
int gt = i - tree.query(instructions[i]);
```

reference: https://zxi.mytechroad.com/blog/tag/binary-indexed-tree/
