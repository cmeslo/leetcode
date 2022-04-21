# 451. Sort Characters By Frequency

## Solution 1: Sort by frequency

```cpp
// 8 ms, Your runtime beats 94.68 % of cpp submissions.
string frequencySort(string s) {
    vector<int> freq(128);
    for (char& c : s)
        freq[c]++;

    vector<pair<int, int>> arr;
    for (int i = 0; i < 128; ++i) {
        if (freq[i])
            arr.push_back({freq[i], i});
    }
    sort(arr.rbegin(), arr.rend());

    string res;
    for (int i = 0; i < arr.size(); ++i)
        res.append(arr[i].first, arr[i].second);
    return res;
}
```

or

```cpp
// 138 ms, Your runtime beats 7.01 % of cpp submissions.
string frequencySort(string s) {
    vector<int> freq(128);
    for (char& c : s)
        ++freq[c];

    sort(s.begin(), s.end(), [&](char& a, char& b) {
        return (freq[a] > freq[b]) || (freq[a] == freq[b] && a < b);
    });

    return s;
}
```
