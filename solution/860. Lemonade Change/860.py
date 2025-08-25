class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = 0
        for x in bills:
            if x == 5:
                five += 1
            elif x == 10:
                ten += 1
                five -= 1
            elif x == 20:
                if ten > 0:
                    ten -= 1
                    five -= 1
                else:
                    five -= 3
            if five < 0:
                return False
        return True
    
