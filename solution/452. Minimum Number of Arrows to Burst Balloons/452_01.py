class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        
        res = 1
        arrow_pos = points[0][1]
        
        for x_start, x_end in points:
            if arrow_pos < x_start:
                res += 1
                arrow_pos = x_end
                
        return res
