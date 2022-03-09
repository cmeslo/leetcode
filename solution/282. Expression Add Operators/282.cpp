class Solution {
public:
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, "", 0L, 0L);
        return ans;
    }
    
private:
    vector<string> ans;
    
    void dfs(const string& num, const int target, int curPos, string preStr, long preVal, long lastVal) {
        if (curPos == num.size()) {
            if (preVal == target)
                ans.push_back(preStr);
            return;
        }
        
        for (int endPos = curPos + 1; endPos <= num.size(); ++endPos) {
            string curStr = num.substr(curPos, endPos - curPos);
            long curVal = stol(curStr);
            
            if (curStr.size() > 1 && curStr[0] == '0') continue;
            
            if (curPos == 0) {
                dfs(num, target, endPos, curStr, curVal, curVal);
            } else {
                dfs(num, target, endPos, preStr+'+'+curStr, preVal + curVal, curVal);
                dfs(num, target, endPos, preStr+'-'+curStr, preVal - curVal, -curVal);
                dfs(num, target, endPos, preStr+'*'+curStr, preVal - lastVal + lastVal * curVal, lastVal * curVal);
            }
        }
    }
};
