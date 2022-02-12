# 2164. Sort Even and Odd Indices Independently

```cpp
vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> A, B;
    int n = nums.size();
    for (int i = 0; i < n; i += 2) {
        A.push_back(nums[i]);
        if (i + 1 < n)
            B.push_back(nums[i + 1]);
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    vector<int> res(n);
    int j = 0;
    for (int i = 0; i < n; i += 2)
        res[i] = A[j++];
    j = 0;
    for (int i = 1; i < n; i += 2)
        res[i] = B[j++];
    return res;
}
```
