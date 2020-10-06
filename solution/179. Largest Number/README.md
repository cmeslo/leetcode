# 179. Largest Number

```cpp
string largestNumber(vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), [](int& a, int& b) {
        return to_string(b) + to_string(a) < to_string(a) + to_string(b);
    });

    string ans = "";
    for (int n : nums)
        ans += to_string(n);

    return ans[0] == '0' ? "0" : ans;
}
```
