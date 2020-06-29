class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const vector<string>& t : tickets)
            _map[t[0]].push_back(t[1]);
        
        // dfs
        vector<string> res;
        
        res.push_back("JFK");
        dfs(res, "JFK", tickets.size());
        
        return ans;
    }
    
private:
    unordered_map<string, vector<string>> _map;
    vector<string> ans;

    void dfs(vector<string>& res, const string cur, int ticketLeft) {
        if (ticketLeft == 0) {
            if (ans.empty()) {
                ans = res;
            } else {
                for (int i = 0; i < ans.size(); i++) {
                    if (res[i] == ans[i]) continue;
                    if (lessLexicalOrder(res[i], ans[i])) ans = res;
                    return;
                }
            }
            return;
        }
        
        if (_map[cur].empty()) return;
        
        vector<string>& list = _map[cur];
        for (int i = 0; i < list.size(); i++) {
            string to = list[i];
            res.push_back(to);
            
            list.erase(list.begin() + i);
            dfs(res, to, ticketLeft-1);
            
            list.insert(list.begin() + i, to);
            res.pop_back();
        }
    }
    
    bool lessLexicalOrder(string a, string b) { // a < b ? true : false
        for (int i = 0; i < 3; i++) {
            if (a[i] == b[i]) continue;
            return a[i] < b[i] ? true : false;
        }
        return false;
    }
};
