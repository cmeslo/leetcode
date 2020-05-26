class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> prefix_sum = new HashMap<Integer, Integer>();
        int sum = 0;
        int ans = 0;
        
        prefix_sum.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            sum += (nums[i] != 0 ? nums[i] : -1);
            if (prefix_sum.containsKey(sum)) {
                int pre_index = prefix_sum.get(sum);
                ans = Math.max(ans, i - pre_index);
            } else {
                prefix_sum.put(sum, i);
            }
        }
        
        return ans;
    }
}
