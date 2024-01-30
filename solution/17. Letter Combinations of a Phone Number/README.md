# 17. Letter Combinations of a Phone Number

## Solution 1: DFS (17_01.cpp)

Time complexity: ```O(4^n)```

Space complexity: ```O(4^n + n)```, which ```4^n``` for ans, ```n``` for cur.

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string cur;
        dfs(digits, 0, cur, res);
        return res;
    }

private:
    const vector<string> m = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void dfs(const string& digits, int i, string& cur, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        for (const char& c : m[digits[i] - '0']) {
            cur.push_back(c);
            dfs(digits, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
```

## Solution 2: BFS (17_02.cpp)

Time complexity: ```O(4^n)```

Space complexity: ```O(2*(4^n))```, one ```4^n``` for ans + one ```4^n``` for tmp.

```cpp
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    const vector<string> m = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> ans;
    ans.push_back("");
    for (char& d : digits) {
        vector<string> tmp;
        for (char c : m[d - '0']) {
            for (string& pre : ans) {
                tmp.push_back(pre + c);
            }
        }
        swap(ans, tmp);
    }
    
    return ans;
}
```
