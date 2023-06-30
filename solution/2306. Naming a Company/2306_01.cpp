class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        unordered_set<string> s(ideas.begin(), ideas.end());
        vector<int> f(26);
        for (string& idea : ideas)
            f[idea[0] - 'a']++;
        
        vector<vector<int>> ab(26, vector<int>(26));
        for (string& idea : ideas) {
            char c = idea[0];
            int j = idea[0] - 'a';
            for (int i = 0; i < 26; ++i) {
                if (!f[i]) continue;
                idea[0] = i + 'a';
                if (s.count(idea))
                    ab[j][i]++;
            }
            idea[0] = c;
        }
        
        for (string& idea : ideas) {
            int j = idea[0] - 'a';
            for (int i = 0; i < 26; ++i) {
                if (!f[i]) continue;
                idea[0] = i + 'a';
                if (s.count(idea)) continue;
                int cnt = (j == i ? f[i] - 1 : f[i]);
                cnt -= ab[i][j];
                res += cnt;
            }
        }
        return res;
    }
};

// c: 1
// d: 1
// t: 2

// coffee time toffee
// 0      1    2

// coffee -> time -> toffee (not ok)
// 0         1       -1

// coffee -> t -> !ok

// time -> coffee -> cime (ok) -> (should not ok!!!)
// 1       0
// j       i 

// time -> c -> !ok
