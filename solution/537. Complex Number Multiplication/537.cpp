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
