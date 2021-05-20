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
