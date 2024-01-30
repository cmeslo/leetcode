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
    if (digits.length() == 0) return {};

    vector<vector<char>> d(10);
    d[0] = {' '};
    d[1] = {};
    d[2] = {'a', 'b', 'c'};
    d[3] = {'d', 'e', 'f'};
    d[4] = {'g', 'h', 'i'};
    d[5] = {'j', 'k', 'l'};
    d[6] = {'m', 'n', 'o'};
    d[7] = {'p', 'q', 'r', 's'};
    d[8] = {'t', 'u', 'v'};
    d[9] = {'w', 'x', 'y', 'z'};

    vector<string> ans = {""};
    for (const char& digit : digits) {
        vector<string> tmp;
        for (const string& pre : ans) {
            for (const char& c : d[digit - '0']) {
                tmp.push_back(pre + c);
            }
        }
        ans.swap(tmp);
    }
    return ans;
}
```

or

```cpp
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) return ans;

    unordered_map<char, vector<char>> m;
    m['2'] = {'a', 'b', 'c'};
    m['3'] = {'d', 'e', 'f'};
    m['4'] = {'g', 'h', 'i'};
    m['5'] = {'j', 'k', 'l'};
    m['6'] = {'m', 'n', 'o'};
    m['7'] = {'p', 'q', 'r', 's'};
    m['8'] = {'t', 'u', 'v'};
    m['9'] = {'w', 'x', 'y', 'z'};

    ans.push_back("");
    for (char& num : digits) {
        vector<string> tmp;
        for (char& d : m[num]) {
            for (string& pre : ans) {
                tmp.push_back(pre + d);
            }
        }
        swap(ans, tmp);
    }
    return ans;
}
```
