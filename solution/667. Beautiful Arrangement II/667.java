class Solution {
    public int[] constructArray(int n, int k) {
        int[] res = new int[n];
        
        for (int i = 0, l = 1, r = n; l <= r; i++) {
            if (k > 1) {
                res[i] = k-- % 2 == 1 ? l++ : r--;
            } else {
                res[i] = l++;
            }
        }
        return res;
    }
}
