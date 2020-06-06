class Solution {

    private int[] prefix_sum;
    private int total_sum;
    private Random rand;
    
    public Solution(int[] w) {
        prefix_sum = new int[w.length];
        total_sum = 0;
        rand = new Random();
        
        for (int i = 0; i < w.length; i++) {
            total_sum += w[i];
            prefix_sum[i] = total_sum;
        }
    }
    
    public int pickIndex() {
        int random_num = rand.nextInt(total_sum)+1;
        int left = 0, right = prefix_sum.length-1;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            if (prefix_sum[mid] < random_num) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
