# 565. Array Nesting

## TLE 做法：

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int s = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int a = i, temp = 1;
            while (nums[a] != i) {
                temp++;
                a = nums[a];
            }
            if (temp > s) s = temp;
        }
        
        return s;
    }
};

```
看完題目後直觀寫出來的做法，也猜到不會那麼簡單，在最後幾個案例超時了。
```
853 / 856 test cases passed.
```

## 565_01.cpp
例子：
```
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
```
拿題目的Example來觀察，由於結果集是一個環，A[0]開始的Set長度是4，中間不論由A[5]、A[6]或者A[2]作起始的環，長度都一樣是4，所以實際上可以跳過不計算。

所以增加一個 visited 數組去記錄是否被訪問過
```cpp
int arrayNesting(vector<int>& nums) {
    int maxS = 0;
    vector<bool> visited(nums.size(), false);

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) continue;
        int a = i, currS = 1;
        while (nums[a] != i) {
            visited[a] = true;
            currS++;
            a = nums[a];
        }
        if (currS > maxS) maxS = currS;
    }

    return maxS;
}
```

## 565_02.cpp
可以不使用額外的 visited 數組，用替換的方法
```cpp
int arrayNesting(vector<int>& nums) {
    int max = 0;

    for (int i = 0; i < nums.size(); ++i) {
        int curr = 1;
        while (nums[i] != i) {
            curr++;
            swap(nums[i], nums[nums[i]]);
        }
        if (curr > max) max = curr;
    }

    return max;
}
```

例子
```
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2
```
比如第一個while循環的過程：
```
A[0] = 6, A[5] = 5
A[0] = 2, A[6] = 6
A[0] = 0, A[2] = 2
```
使到 0, 5, 6, 2 都出現在正確的位置上，不會再被遍歷，略過使用額外的 visited 數組。
