# 587. Erect the Fence

## Solution 1

之前可以 AC, 現在 TLE 了

```cpp
class Solution {
public:
    // Gift wrapping algorithm
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // 這個算法有可能插入 duplicate，所以用 set 去重複
        unordered_set<int> res;
        
        // 找到最左面的點，因為它一定是其中一個答案
        int left = 0;
        for (int i = 0; i < trees.size(); ++i) {
            if (trees[i][0] < trees[left][0])
                left = i;
        }
        res.insert(left);
        
        int cur = left;
        while (true) {
            vector<int> collinear; // collinear保存共線的點index
            int next = 0;
            for (int i = 1; i < trees.size(); ++i) {
                if (i == cur) continue;
                // 判斷 i 處於 cur->next 的左手邊、還是右手邊，
                // 可以用行列式(determinant)、或者矢量積(cross product)來判斷都可以
                // if det = 0: cur, next, i 共線(collinear)
                // if det > 0: cur->i 在 cur->next 的左手邊
                // if det < 0: cur->i 在 cur->next 的右手邊，這是想要的結果
                int det = determinant(trees, cur, next, i);
                if (det > 0) {
                    next = i;
                    collinear.clear();
                } else if (det == 0) {
                    if (distance(trees, cur, next, i)) { // next 處於 cur 和 i 的中間
                        collinear.push_back(next);
                        next = i;
                    } else { // i 處於 cur 和 next 的中間
                        collinear.push_back(i);
                    }
                }
            }
            
            // 所有共線的點，都是答案的一部分
            for (int i : collinear) {
                res.insert(i);
            }
            
            // 走到起點，結束
            if (next == left) break;
            
            res.insert(next);
            // 由最新的答案點 next 作為起點，開始下一個循環
            cur = next;
        }
        
        vector<vector<int>> ans;
        for (int i : res)
            ans.push_back(trees[i]);
        return ans;
    }
    
private:
    // 行列式(determinant)
    // return = 0 if a, b, c 共線
    // return > 0 if ac 在 ab 的左手邊
    // return < 0 if ac 在 ab 的右手邊
    int determinant(vector<vector<int>>& trees, int a, int b, int c) {
        int x1 = trees[b][0] - trees[a][0];
        int y1 = trees[b][1] - trees[a][1];
        int x2 = trees[c][0] - trees[a][0];
        int y2 = trees[c][1] - trees[a][1];
        return x1*y2 - x2*y1;
    }
    
    // return true if b 在 a, c 的中間
    bool distance(vector<vector<int>>& trees, int a, int b, int c) {
        int x1 = trees[b][0] - trees[a][0];
        int y1 = trees[b][1] - trees[a][1];
        int x2 = trees[c][0] - trees[a][0];
        int y2 = trees[c][1] - trees[a][1];
        return x1*x1 + y1*y1 < x2*x2 + y2*y2;
    }
};
```
