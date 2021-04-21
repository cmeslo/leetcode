# 784. Letter Case Permutation

轉換英文字母大小寫，可以用：
```cpp
c = c ^ 32; // xor 32 (1 << 5) to toggle case
```
原因可以看 [ACII表](https://zh.wikipedia.org/wiki/ASCII)。

## Solution: DFS

```cpp
// Your runtime beats 100.00 % of cpp submissions.
// Your memory usage beats 80.27 % of cpp submissions.

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }
    
private:
    void dfs(string& s, int i, vector<string>& ans) {
        if (i >= s.size()) {
            ans.push_back(s);
            return;
        }
        
        dfs(s, i + 1, ans);
        if (isalpha(s[i])) {
            s[i] = s[i] ^ 32; // xor 32 (1 << 5) to toggle case
            dfs(s, i + 1, ans);
            s[i] = s[i] ^ 32;
        }
    }
};
```

or

```cpp
// Your runtime beats 92.61 % of cpp submissions.
// Your memory usage beats 78.57 % of cpp submissions.

vector<string> letterCasePermutation(string S) {
    vector<string> ans;

    function<void(int)> dfs = [&](int i) {
        if (i >= S.size()) {
            ans.push_back(S);
            return;
        }
        dfs(i + 1);
        if (isalpha(S[i])) {
            S[i] ^= 32;
            dfs(i + 1);
            S[i] ^= 32;
        }
    };

    dfs(0);
    return ans;
}
```
