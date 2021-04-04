# 1675. Minimize Deviation in Array

## 解釋

既然數組裡所有元素的上限值都是偶數，

不如先把所有元素的上限值（如果是奇數就乘以 2）塞到一個有序容器裡，

然後重複以下過程：

- 把容器裡最大和最小的元素計算 Deviation，
- 把最大元素取出來後，除以 2、塞回去有序容器裡。

應該甚麼時候停止這個過程？

- 如果最大元素是個奇數，代表它沒有辦法縮小了，是這些有序容器中的頂樑柱；
- 這時有序容器中的最小值、也已經是它自身的最大值（偶數）；
- 上界沒辦法縮小、下界沒辦法增大，Deviation 也沒有辦法縮小了，可以停止了。

例子 [4,1,5,20,3]
```
[4,1,5,20,3]
[4,2,10,20,6] -- 上限
[2,4,6,10,20] -- 放到有序容器中

[2,4,6,10] 20 --> 取出最大元素，Deviation = 20 - 2 = 18
[2,4,6,10,10] <-- 計算完除以2放回去

[2,4,6,10] 10 --> 取出最大元素，Deviation = 10 - 2 = 8
[2,4,5,6,10] <--- 計算完除以2放回去

[2,4,5,6] 10 ---> 取出最大元素，Deviation = 10 - 2 = 8
[2,4,5,5,6] <---- 計算完除以2放回去

[2,4,5,5] 6 ----> 取出最大元素，Deviation = 6 - 2 = 4
[2,3,4,5,5] <---- 計算完除以2放回去

[2,3,4,5] 5 ----> 取出最大元素，Deviation = 5 - 2 = 3
[2,3,4,5] <------ 5已經沒有辦法通過除以2、獲得一個較小的數了，結束、答案等於 3
```

## Solution 1: Set

從上面的例子可以看出，重複值對結果沒有影響，所以這個有序用容可以選擇用 set。

```cpp
int minimumDeviation(vector<int>& nums) {
    set<int> s;
    for (int x : nums)
        s.insert(x % 2 ? x * 2 : x);

    int ans = *rbegin(s) - *begin(s);
    while (*rbegin(s) % 2 == 0) {
        s.insert(*rbegin(s) / 2);
        s.erase(*rbegin(s));
        ans = min(ans, *rbegin(s) - *begin(s));
    }
    return ans;
}
```

## Solution 2: heap

這裡用 priority_queue 比 set 更快（即使 priority_queue 容器裡有重複值），

但要自己維護 heap 裡面的最小值。

```cpp
int minimumDeviation(vector<int>& nums) {
    int mn = INT_MAX;
    priority_queue<int> q;
    for (int x : nums) {
        x = x % 2 ? x * 2 : x;
        q.push(x);
        mn = min(mn, x);
    }

    int ans = INT_MAX;
    while (true) {
        int x = q.top(); q.pop();
        ans = min(ans, x - mn);
        mn = min(mn, x / 2);
        if (x % 2 == 0)
            q.push(x / 2);
        else
            break;
    }
    return ans;
}
```
