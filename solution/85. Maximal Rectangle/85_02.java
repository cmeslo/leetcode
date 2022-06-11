class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int[] H = new int[n + 2];
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                H[j + 1] = matrix[i][j] == '0' ? 0 : H[j + 1] + 1;
            }
            res = Math.max(res, getMaxArea(H));
        }
        return res;
    }
    
    private int getMaxArea(int[] H) {
        int area = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.addLast(0);
        for (int i = 1; i < H.length; ++i) {
            while (H[stack.peekLast()] > H[i]) {
                int h = H[stack.pollLast()];
                int w = i - stack.peekLast() - 1;
                area = Math.max(area, h * w);
            }
            stack.addLast(i);
        }
        return area;
    }
}
