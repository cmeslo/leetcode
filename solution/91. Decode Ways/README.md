# 91. Decode Ways

## Recursive (91_01.cpp)

```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> mem(s.length(), -1);
        return dfs(s, 0, mem);
    }
    
private:
    int dfs(const string& s, int i, vector<int>& mem) {
        int n = s.length();
        if (i >= n) return 1;
        if (s[i] == '0') return 0;
        if (mem[i] != -1) return mem[i];
        
        mem[i] = dfs(s, i + 1, mem);
        
        if (i + 1 < n) {
            if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                mem[i] += dfs(s, i + 2, mem);
        }
        
        return mem[i];
    }
};
```
