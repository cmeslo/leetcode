class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const vector<string>& t : tickets) {
            _trips[t[0]].push_back(t[1]);
        }
        
        for (auto& it : _trips) {
            auto& dests = it.second;
            std::sort(dests.begin(), dests.end());
        }
        
        postOrderTraversal("JFK");
        
        return vector<string>(_route.rbegin(), _route.rend());
    }
    
private:
    unordered_map<string, deque<string>> _trips;
    vector<string> _route;
    
    void postOrderTraversal(string root) {
        auto& dests = _trips[root];
        while (!dests.empty()) {
            const string dest = dests.front();
            dests.pop_front();
            postOrderTraversal(dest);
        }
        _route.push_back(root);
    }
};
