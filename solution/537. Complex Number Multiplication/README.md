# 537. Complex Number Multiplication

```cpp
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto [a, b] = getNum(num1);
        auto [c, d] = getNum(num2);
        // (a + bi) * (c + di) = ac + adi + bci + bdi^2
        return to_string(a*c - b*d) + '+' + to_string(a*d + b*c) + 'i';
    }
    
private:
    pair<int, int> getNum(string& num) {
        istringstream iss(num);
        string str_a, str_b;
        getline(iss, str_a, '+');
        getline(iss, str_b, '+');
        int a = stoi(str_a);
        int b = stoi(str_b);
        return {a, b};
    }
};
```

or

```cpp
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto [a1, b1] = getNum(num1);
        auto [a2, b2] = getNum(num2);
        int a = a1 * a2 - b1 * b2;
        int b = a1 * b2 + a2 * b1;
        return to_string(a) + '+' + to_string(b) + 'i';
    }
    
private:
    pair<int, int> getNum(string& num) {
        int plus = num.find('+');
        int a = stoi(num.substr(0, plus));
        int b = stoi(num.substr(plus + 1, num.size() - 2 - plus));
        return {a, b};
    }
};
```

or

```cpp
string complexNumberMultiply(string num1, string num2) {
    int ra, ia, rb, ib;
    char buff;
    stringstream A(num1), B(num2), ans;
    A >> ra >> buff >> ia >> buff;
    B >> rb >> buff >> ib >> buff;
    ans << ra*rb - ia*ib << '+' << ra*ib + rb*ia << 'i';
    return ans.str();
}
```
