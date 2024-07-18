class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        ready = [room for room in range(n)]
        heapify(ready)
        rooms = []
        
        res = [0] * n
        
        for start, end in sorted(meetings):
            while rooms and rooms[0][0] <= start:
                time, room = heappop(rooms)
                heappush(ready, room)
            
            if ready:
                room = heappop(ready)
                heappush(rooms, [end, room])
            else:
                time, room = heappop(rooms)
                heappush(rooms, [time + end - start, room])
                
            res[room] += 1
            
        return res.index(max(res))
    
        
