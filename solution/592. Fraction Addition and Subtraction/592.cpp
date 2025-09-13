class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);
        int A = 0, B = 1, a, b;
        char _;
        while (iss >> a >> _ >> b) {
            A = A * b + a * B;
            B *= b;
            int g = gcd(A, B);
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};

// A/B + a/b = (Ab + aB) / Bb
