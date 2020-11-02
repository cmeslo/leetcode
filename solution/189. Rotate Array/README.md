# 189. Rotate Array

兩個方法都是 Your runtime beats 99.08 % of cpp submissions.

## 189_01.cpp

最初想到，也是比較直觀的解法

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    if (k == 0 || k == n) return;

    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}
```
## 189_02.cpp

參考了別人的做法，

每次走 k 步，並且把當前數字移到 k 個數字之後，

最後再多加一個 count 變量來記錄已經改了多少個數字

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k %= n;
    if (k == 0 || k == n) return;

    int count = 0;
    int start = 0;

    while (count < n) {
        int curr = start;
        int currVal = nums[curr];

        do {
            int next = (curr + k) % n;
            int nextVal = nums[next];
            nums[next] = currVal; 
            curr = next;
            currVal = nextVal;
            ++count;
        } while (curr != start);

        ++start;
    }
}
```
