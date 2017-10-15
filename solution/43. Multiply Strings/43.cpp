class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        vector<int> pos(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = pos[p2] + mul;
                
                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }
        
        for (int p : pos) if (!(res.empty() && p == 0)) res.push_back(p + '0');
        return res.empty()? "0" : res;
    }
};
