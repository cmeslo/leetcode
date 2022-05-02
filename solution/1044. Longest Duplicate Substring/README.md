# 1044. Longest Duplicate Substring

## Solution: Rolling hash - Version 1 (Collision Check)

```cpp
#define p 10000007

class Solution {
public:
    string longestDupSubstring(string S) {
        int len = S.size();
        if (len == 0) return "";

        roll.resize(len);
        roll[0] = 1;
        for (int i = 1; i < len; i++) roll[i] = (roll[i-1]*26) % p;

        int left = 1, right = len, mid; // left cannot be 0, because window size (mid) cannot be 0.
        
        while (left < right) {
            mid = left + (right-left)/2;
            string temp = "";
            
            if (search(S, len, mid, temp) == true) {
                if (temp.size() > ans.size()) ans = temp;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return ans;
    }
private:
    vector<int> roll;
    string ans;

    bool search(const string& s, int len, int size, string& ans) {
        unordered_map<int, vector<int>> m;

        int hash = 0;
        for (int i = 0; i < size; i++) {
            hash = (hash + (toInt(s[i])*roll[size-i-1])%p) % p;
        }
        m[hash].push_back(0);

        for (int i = size; i < len; i++) {
            int rm = i - size;
            hash = ((hash - toInt(s[rm])*roll[size-1])%p + p) % p; // add mod to avoid negative value
            hash = (hash*26 + toInt(s[i])%p) % p;

            if (m.find(hash) != m.end()) {

                string curr = s.substr(rm+1, size);
                for (auto start : m[hash]) {
                    string temp = s.substr(start, size);
                    if (curr.compare(temp) == 0) {
                        ans = temp;
                        return true;
                    }
                }

            } else {
                m[hash].push_back(rm + 1);
            }
        }
        return false;
    }

    int toInt(const char& c) {
        return c - 'a';
    }
};
```

## Solution: Rolling hash - version 2

```
 b a n a n a
[     ]

b*p^2 + a*p^1 + n
        a*p^2 + n*p^1 + a
```

```cpp
class Solution {
public:
    string longestDupSubstring(string s) {
        startPos = -1;
        
        int n = s.size();
        vector<uint64_t> p(n);
        p[0] = 1;
        p[1] = 31;
        for (int i = 2; i < n; ++i)
            p[i] = p[i - 1] * p[1];
        
        int l = 0, r = n - 1;
        while (l < r) {
            int m = r - (r - l) / 2;
            if (checkOK(s, m, p))
                l = m;
            else
                r = m - 1;
        }
        return startPos == -1 ? "" : s.substr(startPos, l);
    }
    
private:
    int startPos;
    
    bool checkOK(string& s, int len, vector<uint64_t>& p) {
        if (len <= 0) return false;
        unordered_set<uint64_t> seen;
        
        uint64_t hash = 0;
        for (int i = 0; i < s.size(); ++i) {
            hash = hash * p[1] + s[i] - 'a';
            if (i >= len - 1) {
                if (seen.count(hash)) {
                    startPos = i - len + 1;
                    return true;
                }
                seen.insert(hash);
                hash -= (s[i - len + 1] - 'a') * p[len - 1];
            }
        }
        return false;
    }
};
```
