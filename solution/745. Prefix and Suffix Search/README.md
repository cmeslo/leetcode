# 745. Prefix and Suffix Search

## Solution 1: Brute Force (map)

### 解釋

暴力枚舉所有可能性並放到 map 裡：

```
_
_a
_ap
_appl
_apple
e_
e_a
e_ap
e_appl
e_apple
le_
le_a
le_ap
le_app
le_appl
le_apple
...
apple_
...
apple_apple
```

### Code

```cpp
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int index = 0;
        for (string& w : words) {
            int n = w.length();
            vector<string> prefixes(n + 1, "");
            vector<string> suffixes(n + 1, "");
            for (int i = 1; i <= n; ++i) {
                prefixes[i] = prefixes[i - 1] + w[i - 1];
                suffixes[i] = w[n - i] + suffixes[i - 1];
            }
            for (string& pre : prefixes)
                for (string& suf : suffixes)
                    filter_[pre + '_' + suf] = index;
            index++;
        }
    }
    
    int f(string prefix, string suffix) {
        auto it = filter_.find(prefix + '_' + suffix);
        if (it != filter_.end())
            return it->second;
        return -1;
    }
    
private:
    unordered_map<string, int> filter_;
};
```
