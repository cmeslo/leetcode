class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = Counter(students)

        for s in sandwiches:
            if count[s] == 0:
                return count[1 - s]
            count[s] -= 1
        
        return 0
    
