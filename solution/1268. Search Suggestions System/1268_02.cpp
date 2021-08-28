class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(begin(products), end(products));
        
        vector<vector<string>> ans;
        auto it = begin(products);
        string cur = "";
        for (char& c : searchWord) {
            cur += c;
            it = lower_bound(it, end(products), cur);
            vector<string> suggested;
            for (int i = 0; i < 3 && it + i < end(products); ++i) {
                string& s = *(it + i);
                if (s.find(cur) != 0) break;
                suggested.push_back(s);
            }
            ans.push_back(suggested);
        }
        return ans;
    }
};
