# 169. Majority Element

## Solution 1: Hashmap

```cpp
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m(nums.size());

    for (int x : nums) {
        m[x]++;
        if (m[x] > nums.size() / 2) return x;
    }
    return 0;
}
```

## Solution 2: Moore Voting Algorithm

```cpp
int majorityElement(vector<int>& nums) {
    int res = 0, cnt = 0;
    for (int x : nums) {
        if (cnt == 0) {
            res = x;
            cnt++;
        } else {
            res == x ? cnt++ : cnt--;
        }            
    }
    return res;
}
```

## Solution 3: Bit Manipulation

32 位 int 裡，如果某個位置上 1 出現的次數超過 ```n / 2``` 次，就代表這個位置應該出現 1。

```cpp
int majorityElement(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        int cnt = 0;
        for (int x : nums) {
            if ((x >> i) & 1)
                ++cnt;
        }
        ans |= cnt > nums.size() / 2 ? (1 << i) : 0;
    }
    return ans;
}

// x x x x x b b


// 0 0 0 1 0
// 0 0 0 1 0
// 0 0 0 1 0
// 0 0 0 1 0
// 0 1 0 0 1

// 0 1 1
// 0 1 0
// 0 1 1
```
