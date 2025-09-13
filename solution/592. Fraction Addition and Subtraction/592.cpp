class Solution {
public:
    string fractionAddition(string e) {
        int n = e.size();
        vector<string> A;
        for (int i = 0, j = 1; j <= n; ++j) {
            if (e[j] == '+' || e[j] == '-' || j == n) {
                A.push_back(e.substr(i, j - i));
                i = j;
            }
        }
        vector<pair<int, int>> B;
        for (string& a : A) {
            istringstream iss(a);
            string cur = "";
            bool handleUp = true;
            int up = 0, down = 0;
            while (getline(iss, cur, '/')) {
                if (handleUp) {
                    up = stoi(cur);
                    handleUp = false;
                } else {
                    down = stoi(cur);
                }
            }
            B.push_back({up, down});
        }
        
        int l = 1;
        for (auto& [_, down] : B) {
            l = lcm(l, down);
        }
        
        int finalUp = 0;
        for (auto& [up, down] : B) {
            // cout << up << "/" << down << endl;
            finalUp += l / down * up;
        }
        int g = gcd(finalUp, l);
        finalUp /= g;
        l /= g;
        
        return finalUp == 0 ? "0/1" : to_string(finalUp) + '/' + to_string(l);
    }
};
