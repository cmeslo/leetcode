class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size(), res = 0, total = 0;
        for (int i = n - 1; i >= 0 && A[i] + total > 0; --i) {
            total += A[i];
            res += total; // 前面新加一道菜, 全部已有的菜延後一個 unit 的時間煮
        }
        return res;
    }
};


// x x x x x x

// 前面新加一道菜, 全部已有的菜延後一個 unit 的時間煮

//       3*1 + 4*2 = 11
// 2*1 + 3*2 + 4*3 = 2 + 11 + (3+4) = 20

// res = res + A[i] + total
// total = total + A[i]
// 或者
// res += A[i] + total;
// total += A[i];
// 都能理解

// 但應該甚麼時後停 ?
// 如果 res + total 反而變小了, 就要停止, 因為 total < 0 的話, 往後疊加也只會帶來更負面的影響(下一輪只會加個負數)
// total = 0 沒有負面影響, 但以後也不會再有正面影響, 也可以停了
