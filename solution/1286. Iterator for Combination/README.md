# 1286. Iterator for Combination

## Solution 1: Use bit masking to generate all the combinations

```cpp
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        int size = characters.size();
        
        for (int n = pow(2, size) - 1; n >= 0; n--) {
            int bitCount = 0;
            for (int j = 0; j < size; j++) {
                if ((n >> j) & 1) bitCount++;
                if (bitCount > combinationLength) break;
            }
            
            if (bitCount == combinationLength) {
                string combination;
                for (int j = size - 1; j >= 0; j--)
                    if ((n >> j) & 1) combination += characters[size-j-1];
                _combinations.push(combination);
            }
        }
    }
    
    string next() {
        string next = _combinations.front();
        _combinations.pop();
        return next;
    }
    
    bool hasNext() {
        return !_combinations.empty();
    }
    
private:
    queue<string> _combinations;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

## Solution 2: DFS

```cpp
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
```
