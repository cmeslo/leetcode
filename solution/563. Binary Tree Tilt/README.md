# 563. Binary Tree Tilt

## Solution

計算 Tilt 需要用到：左子樹的Tilt，右子樹的Tilt，根的val

觀察到處理順序是：左子樹 > 右子樹 > 根

所以可以用 Postorder Traversal

### C++

```cpp
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        postOrderTraversal(root, ans);
        return ans;
    }

private:
    int postOrderTraversal(TreeNode* root, int& ans) {
        if (!root) return 0;
        int leftSum = postOrderTraversal(root->left, ans);
        int rightSum = postOrderTraversal(root->right, ans);
        ans += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
};
```

### Java

```java
class Solution {
    public int findTilt(TreeNode root) {
        dfs(root);
        return res;
    }
    
    private int res = 0;
    
    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int l = dfs(root.left);
        int r = dfs(root.right);
        res += Math.abs(l - r);
        return root.val + l + r;
    }
}
```
