# 645. Set Mismatch

## Solution 1 - sort (645_01.cpp)

```cpp
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(2, 0);
    bool found = false;

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i - 1] == nums[i]) res[0] = nums[i];
        if (!found && nums[i] != i + 1) {
            res[1] = i + 1;
            if (nums[i] > i + 1) found = true;
        }
    }
    return res;
}
```

## Solution 2 - map (645_02.cpp)

```cpp
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> m(n + 1);
    for (int x : nums)
        ++m[x];

    vector<int> ans(2);
    for (int x = 1; x <= n; ++x) {
        if (m[x] == 2)
            ans[0] = x;
        if (m[x] == 0)
            ans[1] = x;
        if (ans[0] && ans[1])
            return ans;
    }
    return ans;
}
```

## Solution 3 - mark (645_03.cpp)

Make nums negative one by one, so the duplicate one will become positive.

```cpp
vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans(2);

    for (int x : nums) {
        if (nums[abs(x) - 1] < 0)
            ans[0] = abs(x);
        else
            nums[abs(x) - 1] *= -1;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            ans[1] = i + 1;
            break;
        }
    }
    return ans;
}
```

## Solution 4 - swap (645_04.cpp)

```cpp
vector<int> findErrorNums(vector<int>& nums) {
    for (int& x : nums)
        while (nums[x - 1] != x)
            swap(x, nums[x - 1]);

    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != i + 1)
            return {nums[i], i + 1};

    return {};
}
```
