class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1] - arr[0]
        return all(i - j == diff for i, j in zip(arr[1:], arr[:-1]))
