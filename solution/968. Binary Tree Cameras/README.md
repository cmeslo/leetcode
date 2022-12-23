# 968. Binary Tree Cameras

## Solution: Recursive

### 解釋

梅花間竹的策略是錯誤的，例子：

```
    0
   /
  0  <--------這裡設置一個 camera
   \
    0
   /
  0
   \
    0 <--------這裡設置一個 camera
   /
  0
```
梅花間竹的策略會認為要 3 個 camera，而實際上只要 2 個 camera 就可以全部 covered，

應該考慮每個 node 有三種狀態 ```NONE```, ```CAMERA```, ```COVERED```，而當前 node 的狀態、由孩子決定，

base case：葉子節點應該返回 ```NONE```，所以葉子的孩子 (nullptr) 返回 ```COVERED```。

### Code

```cpp
enum class State { NONE = 0, CAMERA = 1, COVERED = 2 };

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == State::NONE) ++res_;
        return res_;
    }
    
private:
    int res_ = 0;
    
    State dfs(TreeNode* root) {
        if (!root) return State::COVERED;
        
        State left = dfs(root->left);
        State right = dfs(root->right);
        
        if (left == State::NONE || right == State::NONE) {
            ++res_;
            return State::CAMERA;
        }
        
        if (left == State::COVERED && right == State::COVERED) return State::NONE;
        
        return State::COVERED; // 經過上面兩個 if 之後，left, right 中只少有一個 camera，而另一個是 camera 或者 covered
    }
};
```
