# 667. Beautiful Arrangement II #

Picking numbers from the head and tail, and approach the middle until k = 1.

```cpp
vector<int> constructArray(int n, int k) {
    vector<int> ans;
    for (int i = 1, j = n; i <= j;) {
        if (k > 1)
            ans.push_back(k-- % 2 ? i++ : j--);
        else
            ans.push_back(i++);
    }
    return ans;
}
```

為什麼 ```k-- % 2 ? i++ : j--```，而當 k = 1 時，就取 i++？

因為當 k = 2 最後一次進入這個 if 時，如果我從某一邊取數、比如右邊，

之後當 k = 1 時，我就想一直由左邊取數、這樣接下來所有的 diff 都是等於 1 了。

所以當 k % 2 導至 j-- 時，之後我取的都是 i++

所以其實也可以這樣寫
```cpp
vector<int> constructArray(int n, int k) {
    vector<int> ans;
    for (int i = 1, j = n; i <= j;) {
        if (k > 1)
            ans.push_back(k-- % 2 ? j-- : i++);
        else
            ans.push_back(j--);
    }
    return ans;
}
```

```
例如：n = 5, k = 3
1,2,3,4,5
取1，k = 3
取5，k = 2
取2，k = 1 ←-當 k = 1 時，一直取同一邊
取3，k = 1
取4，k = 1
```

[reference](https://discuss.leetcode.com/topic/101113/c-java-clean-code-4-liner)
