# 969. Pancake Sorting

模擬過程，

每次先選"尚未排序的"最大 Pancake，先反轉到最頂，然後再反轉一次到"尚未排序的"最底。

```cpp
vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> ans;

    for (int i = 0; i < n - 1; ++i) {
        int p = max_element(A.begin(), A.end() - i) - A.begin();
        ans.push_back(p + 1);
        std::reverse(A.begin(), A.begin() + p + 1);
        ans.push_back(n - i);
        std::reverse(A.begin(), A.begin() + n - i);
    }

    return ans;
}
```
