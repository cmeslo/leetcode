# 12. Integer to Roman

```cpp
string intToRoman(int num) {
    vector<int> values{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbols{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string ans = "";
    int i = 0;
    while (num) {
        if (num >= values[i]) {
            ans += symbols[i];
            num -= values[i];
        } else {
            ++i;
        }
    }
    return ans;
}
```

or

```cpp
string intToRoman(int num) {
    static const vector<int> A = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const vector<string> S = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string res = "";
    for (int i = 0; i < A.size(); ++i) {
        while (num >= A[i]) {
            res += S[i];
            num -= A[i];
        }
    }
    return res;
}
```
