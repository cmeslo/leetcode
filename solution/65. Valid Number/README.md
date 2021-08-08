# 65. Valid Number

寫得不太簡潔

```cpp
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        
        auto e = s.find('e');
        auto E = s.find('E');
        if (e != string::npos || E != string::npos) {
            e = (e != string::npos ? e : E);
            string left = s.substr(0, e);
            string right = s.substr(e + 1);
            if (!isInteger(right))  return false;
            if (!isDecimal(left) && !isInteger(left)) return false;
            return true;
        }
        
        return isDecimal(s) || isInteger(s);
    }
    
private:
    bool isDecimal(string& s) {
        if (s.empty()) return false;
        
        int n = s.size();
        int cnt_dot = 0;
        auto dot = s.find('.');
        
        if (dot != string::npos) {
            int cnt_digit = 0;
            if ((int)dot + 1 < n && isdigit(s[dot + 1])) ++cnt_digit;
            if ((int)dot - 1 >= 0 && isdigit(s[dot - 1])) ++cnt_digit;
            if (cnt_digit == 0) return false;
        } else {
            return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0) return false;
            } else if (s[i] == '.') {
                if (++cnt_dot > 1)
                    return false;
            } else if (!isdigit(s[i])) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isInteger(string& s) {
        if (s.empty()) return false;
        
        int n = s.size();
        int cnt_digit = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0) return false;
            } else {
                if (isdigit(s[i]))
                    ++cnt_digit;
                else
                    return false;
            }
        }
        return cnt_digit != 0;
    }
};
```
