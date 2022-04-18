# 151. Reverse Words in a String

## Solution 1: 自己處理空格

```cpp
string reverseWords(string s) {
    string ans;
    int i = 0, n = s.length();
    while (true) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;
        int j = i + 1;
        while (j < n && s[j] != ' ') j++;
        if (ans.length() == 0) ans = s.substr(i, j-i);
        else ans = s.substr(i, j-i) + ' ' + ans;
        i = j + 1;
    }
    return ans;
}
```

## Solution 2: 使用 stringstream

```cpp
string reverseWords(string s) {
    istringstream ss(s);
    string word, res;
    ss >> res;
    while (ss >> word)
        res = word + ' ' + res;
    return res;
}
```

## Solution 3: 反轉再反轉

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string res = remove_spaces(s);
        reverse_words(res);
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    void reverse_words(string& s) {
        int n = s.size();
        int i = 0, j = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
    
    string remove_spaces(string& s) {
        int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        return s.substr(0, i);
    }
};


// "the sky is blue"
// "eht yks si eulb"
// "blue is sky the"
```
