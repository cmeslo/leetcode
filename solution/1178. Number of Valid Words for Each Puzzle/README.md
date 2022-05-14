# 1178. Number of Valid Words for Each Puzzle

## Solution: Bit Manipulation + HashMap

由於 ```puzzles[i].length == 7```，各種組合是 ```2^7 = 128```，所以可以暴力嘗試所有可能性。

```O(puzzles.length * state * puzzles[i].length) = O(10^4 * 128 * 7)```，大約是 ```O(10^6)```，是可接受的。

```cpp
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    vector<int> ans;
    unordered_map<int, int> freq;
    for (string& w : words) {
        int mask = 0;
        for (char& c : w)
            mask |= (1 << (c - 'a'));
        freq[mask]++;
    }

    for (string& p : puzzles) {
        int total = 0;
        int l = p.size() - 1;
        for (int state = 0; state < (1 << l); ++state) {
            int mask = 1 << (p[0] - 'a');
            for (int j = 0; j < l; ++j) {
                if (state & (1 << j))
                    mask |= 1 << (p[j + 1] - 'a');
            }
            auto it = freq.find(mask);
            if (it != freq.end())
                total += it->second;
        }
        ans.push_back(total);
    }
    return ans;
}
```
