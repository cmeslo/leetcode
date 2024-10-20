class Solution:
    def checkValidString(self, s: str) -> bool:
        cmin = cmax = 0
        for c in s:
            if c == '(':
                cmin += 1
                cmax += 1
            elif c == ')':
                cmin -= 1
                cmax -= 1
            else:
                cmax += 1
                cmin -= 1
            
            if cmax < 0:
                return False
            if cmin < 0:
                cmin = 0
                
        return cmin == 0
    
