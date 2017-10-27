class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        dfs(n, n, n, "", res);
        return res;
    }
    
    public void dfs(int n, int left, int right, String out, List<String> res) {
        if (left < 0 || left < 0 || right < left) return;
        
        if (left == 0 && right == 0) {
            res.add(out);
        }
        dfs(n, left - 1, right, out + "(", res);
        dfs(n, left, right - 1, out + ")", res);
    }
}
