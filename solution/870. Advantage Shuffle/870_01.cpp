class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int, int> m;
        for (int a : A) ++m[a];
        
        vector<int> ans;
        for (int b : B) {
            auto it = m.upper_bound(b);
            it = it != m.end() ? it : m.begin();
            ans.push_back(it->first);
            if (--it->second == 0)
                m.erase(it);
        }
    
        return ans;
    }
};
