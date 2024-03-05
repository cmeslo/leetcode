class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> m;
        m[0] = 0;
        for (auto& f : flowers) {
            m[f[0]]++;
            m[f[1] + 1]--;
        }
        
        int sum = 0;
        for (auto& [k, v] : m) {
            v += sum;
            sum = v;
        }
        
        vector<int> ans;
        for (int p : persons) {
            auto it = prev(m.upper_bound(p));
            ans.push_back(it->second);
        }
        return ans;
    }
};

// m[0] = 0; 讓 prev(m.upper_bound(p)) 一定存在，不加這句的話、也可以：

// auto it = m.upper_bound(p);
// if (it != m.begin())
//     ans.push_back(prev(it)->second);
// else
//     ans.puhs_back(0);
