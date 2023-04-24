class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        unordered_set<string> B(bank.begin(), bank.end());
        queue<string> q;
        B.erase(start);
        q.push(start);
        string G = "ACGT";
        int res = 0;
        while (!q.empty()) {
            ++res;
            for (int size = q.size(); size > 0; --size) {
                string cur = q.front(); q.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    char old = cur[i];
                    for (char g : G) {
                        cur[i] = g;
                        if (B.count(cur)) {
                            if (cur == end) return res;
                            B.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = old;
                }
            }
        }
        return -1;
    }
};
