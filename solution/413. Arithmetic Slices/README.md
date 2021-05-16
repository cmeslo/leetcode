# 413. Arithmetic Slices

## 解釋：

```
例子：
[1,3,5,7,9]

[1,3 5] ======> {[1,3,5]} ---------------------------------------------------------> 1
[1,3,5,7] ====> {[1,3,5], [1,3,5,7], [3,5,7]} -------------------------------------> 1 + 2
[1,3,5,7,9] ==> {[1,3,5], [1,3,5,7], [3,5,7], [1,3,5,7,9], [3,5,7,9], [5,7,9]} ----> 1 + 2 + 3

答案 = 6
```
規律：每添加一個符合等差數列的數字，結果 += （上一輪添加的數字 + 1），如果中間斷了就重新來過。

## Code：
```cpp
int numberOfArithmeticSlices(vector<int>& A) {
    int ans = 0, cnt = 0;
    for (int i = 2; i < A.size(); ++i) {
        cnt = (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) ? cnt + 1 : 0;
        ans += cnt;
    }
    return ans;
}
```