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
