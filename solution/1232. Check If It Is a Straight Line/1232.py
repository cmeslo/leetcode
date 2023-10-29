class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        (x0, y0), (x1, y1) = coordinates[:2]
        for x, y in coordinates:
            if (y1 - y0) * (x - x0) != (y - y0) * (x1 - x0):
                return False
        return True

# (y2 - y1) / (x2 - x1) = (y3 - y1) / (x3 - x1)
# (y2 - y1) * (xi - x1) = (yi - y1) * (x2 - x1)
