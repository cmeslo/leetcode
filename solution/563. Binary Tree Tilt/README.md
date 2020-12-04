# 563. Binary Tree Tilt

計算 Tilt 需要用到：左子樹的Tilt，右子樹的Tilt，根的val

觀察到處理順序是：左子樹 > 右子樹 > 根

所以可以用 Postorder Traversal

## 563.cpp

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
