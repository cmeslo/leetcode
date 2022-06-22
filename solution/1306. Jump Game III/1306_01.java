class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> seen = new HashSet<>();
        seen.add(start);
        q.offer(start);
        while (!q.isEmpty()) {
            int i = q.poll();
            if (arr[i] == 0) return true;
            int l = i - arr[i];
            int r = i + arr[i];
            if (l >= 0 && seen.add(l)) q.offer(l);
            if (r < arr.length && seen.add(r)) q.offer(r);
        }
        return false;
    }
}
