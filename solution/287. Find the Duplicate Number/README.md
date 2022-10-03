# 287. Find the Duplicate Number

## Solution 1: Binary search (287_01.cpp)

由於是長度 n + 1，而只有 n 個數，Example:

n + 1 = 11
```
1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10
```
```
left = 1, mid = 5, right = 10
```
中間切一刀，左面或右面長度會多一點，不斷分割、最後找到重複數

時間複雜度： ```O(nlogn)```、空間複雜度： ```O(1)```

### Code:
```cpp
int findDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size()-1, mid;

    while (left < right) {
        mid = left + ((right-left)>>1);

        int cnt = 0;
        for (int n : nums) {
            if (n <= mid) cnt++;
        }

        if (cnt > mid)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
```

## Solution 2: 找環 (287_02.cpp)

Floyd cycle detection algorithm, take a look in [142. Linked List Cycle II](https://github.com/cmeslo/leetcode/tree/master/solution/142.%20Linked%20List%20Cycle%20II)

時間複雜度： ```O(n)```、空間複雜度： ```O(1)```

### Code:
```cpp
int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }

    fast = 0;
    while (true) {
        slow = nums[slow];
        fast = nums[fast];
        if (slow == fast) break;
    }

    return slow;
}
```

### proof 1:
Why they definitely meet if a cycle exists?

可以舉例知道，無論免子 <strong>差奇數步還是偶數步</strong> 就可以追到烏龜，追到後他們總能夠相遇。

### proof 2:
由 <strong>起點</strong> 到 <strong>環的起點</strong>，相當於 <strong>相遇點</strong> 到 <strong>環的起點</strong> 的距離？

關鍵是證明 x mod L = z

解釋:

https://www.youtube.com/watch?v=9YTjXqqJEFE

https://www.quora.com/How-do-I-prove-that-the-tortoise-and-hare-in-Floyd-s-cycle-detection-algorithm-definitely-meet-if-a-cycle-exists-How-do-I-determine-the-starting-point-of-a-cycle-in-a-linked-list

## Solution 3: 標記負號

```cpp
int findDuplicate(vector<int>& nums) {
    for (int a : nums) {
        int x = abs(a);
        if (nums[x] < 0)
            return x;
        nums[x] *= -1;
    }
    return -1;
}
```
