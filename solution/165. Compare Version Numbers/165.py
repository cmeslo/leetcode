class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # A = [int(v) for v in version1.split(".")]
        # B = [int(v) for v in version2.split(".")]
        
        A = list(map(int, version1.split('.')))
        B = list(map(int, version2.split('.')))
        
        for a, b in zip_longest(A, B, fillvalue=0):
            if a > b:
                return 1;
            if a < b:
                return -1
        return 0
    
