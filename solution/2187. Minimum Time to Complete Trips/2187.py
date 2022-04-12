class Solution(object):
    def minimumTime(self, time, totalTrips):
        """
        :type time: List[int]
        :type totalTrips: int
        :rtype: int
        """
        def count(t):
            res = 0
            for x in time:
                res = res + (t // x)
            return res
        
        l, r = 0, sys.maxint
        while l < r:
            mid = (l + r) // 2
            trips = count(mid)
            if trips < totalTrips:
                l = mid + 1
            else:
                r = mid
        return l
