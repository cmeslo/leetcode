class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, 0, combinationLength, "");
        index = 0;
    }
    
    string next() {
        return C[index++];
    }
    
    bool hasNext() {
        return index < C.size();
    }
    
private:
    vector<string> C;
    int index;
    
    void dfs(string& characters, int i, int len, string cur) {
        if (cur.size() == len) {
            C.push_back(cur);
            return;
        }
        if (i >= characters.size())
            return;
        dfs(characters, i + 1, len, cur + characters[i]);
        dfs(characters, i + 1, len, cur);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
