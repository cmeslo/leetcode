class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> q1, q2;
        unordered_set<string> dead(begin(deadends), end(deadends)); // visited
        
        string init = "0000";
        if (dead.count(init) || dead.count(target)) return -1;
        if (init == target) return 0;
        dead.insert(init);
        dead.insert(target);
        q1.insert(init);
        q2.insert(target);
        
        int level = 0;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size())
                swap(q1, q2);
            
            unordered_set<string> q;
            for (const string& cur : q1) {
                for (int i = 0; i < 4; ++i) {
                    string next = cur;
                    for (int j = -1; j <= 1; j += 2) {
                        next[i] = (cur[i] - '0' + j + 10) % 10 + '0';
                        if (q2.count(next)) return level + 1;
                        if (dead.count(next)) continue;
                        dead.insert(next);
                        q.insert(next);
                    }
                }
            }
            swap(q1, q);
            ++level;
        }
        return -1;
    }
};
